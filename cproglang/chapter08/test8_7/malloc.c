/* malloc.c */
#include "syscalls.h"
#define	MAXBYTES	(unsigned) 10240

static unsinged maxalloc;	/* max number of units allocated */
static Header base;			/* empty list to get started */
static Header *freep = NULL;	/* start of free list */

/* malloc: general-purpose storage allocator */
void *malloc(unsigned nbytes)
{
	Header *p, *prevp;
	static Header *morecore(unsigned);
	unsigned nunits;
	
	if (nbytes > MAXBYTES) {	/* not more than MAXBYTES */
		fprintf(stderr,
				"alloc: can't allocate more than %u bytes\n",
				MAXBYTES);
		return NULL;
	}
	nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
	if ((prevp = freep) == NULL) {		/* û�п������� */
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}
	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
		if (p->s.size >= nunits) {		/* �㹻�� */
			if (p->s.size == nunits)	/* ���� */
				prevp->s.ptr = p->s.ptr;
			else {		/* ����ĩβ���� */
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p+1);
		}
		if (p == freep)		/* �ջ��Ŀ������� */
			if ((p = morecore(nunits)) == NULL)
				return NULL;	/* û��ʣ��Ĵ洢�ռ� */
	}
}

#define	NALLOC	1024		/* minimum #units to request */

/* morecore: ask system for more memory */
static Header *morecore(unsigned nu)
{
	char *cp, *sbrk(int);
	Header *up;
	
	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if (cp == (char *) -1)		/* no space at all */
		return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	maxalloc = (up->s.size > maxalloc) ? up->s.size : maxalloc;
	free((void *)(up+1));
	return freep;
}

/* free: put block ap in free list */
void free(void *ap)
{
	Header *bp, *p;
	
	bp = (Header *)ap - 1;		/* point to block header */
	if (bp->s.size == 0 || bp->s.size > maxalloc) {
		fprintf(stderr, "free: can't free %u units\n",
				bp->s.size);
		return;
	}
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break;		/* ���ͷŵĿ�������Ŀ�ͷ��ĩβ */
	
	if (bp + bp->s.size == p->s.ptr) {	/* ����һ���ڿ�ϲ� */
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else
		bp->s.ptr = p->s.ptr;
	if (p + p->s.size == bp) {			/* ����һ���ڿ�ϲ� */
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else
		p->s.ptr = bp;
	freep = p;
}

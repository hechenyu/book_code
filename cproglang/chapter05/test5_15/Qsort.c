/* Qsort.c */
 
/* qsort�������Ե���˳���v[left], ..., v[right]�������� */
void qsort(void *v[], int left, int right,
			int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	
	if (left >= right) 		/* �������Ԫ�ظ���С��2����ִ���κβ��� */
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left+1; i <= right; i++) 
		if ((*comp)(v[i], v[left]) < 0) 
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

 
 

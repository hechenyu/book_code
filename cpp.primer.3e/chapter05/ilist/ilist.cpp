/* --------------->> ilist.cpp <<---------------- */
#include <iostream>
#include "ilist.h" 

ilist_item *ilist::find(int value)
{   // �������в���ֵΪvalue�ĵ�һ���ڵ� 
    ilist_item *ptr = _at_front;
    while (ptr) {
        if (ptr->value() == value)
            break;
        ptr = ptr->next();
    }
    
    return ptr;
}

void ilist::display(std::ostream &os)
{   // ˳����ʾ�����е����нڵ� 
    os << "\n( " << _size << " )( ";
    
    ilist_item *ptr = _at_front;
    while (ptr) {
        os << ptr->value() << " ";
        ptr = ptr->next();
    }
    os << ")\n";
}

void ilist::remove_all()
{   // ɾ�������е����нڵ� 
    while (_at_front)
        remove_front();
    
    _size = 0;
    _at_front = _at_end = 0;
}

int ilist::remove(int value)
{
    ilist_item *plist = _at_front;
    int elem_cnt = 0;
    
    while (plist && plist->value() == value) {  // ɾ������ͷֵΪvalue�Ľڵ� 
        plist = plist->next();
        remove_front();
        ++elem_cnt;
    }
    
    if (!plist)     // ��գ����� 
        return elem_cnt;
        
    ilist_item *prev = plist;   // �˴���plist��ָ�ڵ��ֵ������value 
    plist = plist->next();      // plist����һ���ڵ� 
    
    while (plist) {
        if (plist->value() == value) {  // ���plist��ָ�ڵ��ֵ����value
            prev->next(plist->next());  // prev->_next = plist->_next
            delete plist;
            ++elem_cnt;
            bump_down_size();
            plist = prev->next();
            if (!plist) {
                _at_end = prev;
                return elem_cnt;
            }
        } else {    // ���plist��ָ�ڵ��ֵ������value
            prev = plist;
            plist = plist->next();
        }
    }
    
    return elem_cnt;
} 
        
void ilist::concat(const ilist &il)
{   // ��il��������нڵ㸽��(����)��this����ĺ��� 
    ilist_item *ptr = il._at_front;
    while (ptr) {
        insert_end(ptr->value());
        ptr = ptr->next();
    }
}

void ilist::reverse()
{   // ������ת(��תԪ�ص�˳��) 
	if (!_at_end)
	   return;
	   
    ilist_item *ptr = _at_front;
    ilist_item *prev = 0;
    
    _at_front = _at_end;
    _at_end = ptr;
    
    while (ptr != _at_front) {
        ilist_item *tmp = ptr->next();
        ptr->next(prev);
        prev = ptr;
        ptr = tmp;
    }
    
    _at_front->next(prev);
}

void ilist::reverse2()
{	// Ч��ͬreverse, �����㷨�Ǻ���ʵ�ֵ�, ����Lippman��
	if (!_at_end)
		return;
	
	ilist_item *ptr = _at_front;
    ilist_item *prev = 0;
    
    _at_front = _at_end;
    _at_end = ptr;
	
	while (ptr != _at_front) {
		prev = ptr->next();
		ptr->next(_at_front->next());
		_at_front->next(ptr);
		ptr = prev;
	}
}

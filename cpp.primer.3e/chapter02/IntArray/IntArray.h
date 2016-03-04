/* ---------->> IntArray.h <<---------- */
#ifndef	INTARRAY_H
#define	INTARRAY_H

class IntArray {
public:
	// ���캯��
	explicit IntArray(int sz = DefaultArraySize);
	IntArray(int *array, int array_size); 
	IntArray(const IntArray &rhs); 
	
	// ��������
	~IntArray() {delete[] ia;}
	
	// ����ڲ���Ȳ���: #2b
	bool operator==(const IntArray&) const;
	bool operator!=(const IntArray&) const;
	
	// �±������
	virtual int &operator[](int index);
	
	// ��ֵ������: #2b
	IntArray& operator=(const IntArray&);
	virtual int size() const { return _size; }	// #1 
	virtual void sort();		// #4
	virtual int min() const;	// #3a
	virtual int max() const;	// #3b
	
	// ������������ҵ�
	// ���ص�һ�γ��ֵ�����
	// ���򷵻�-1
	virtual int find(int value) const;	// #3c
	
protected:
	// ˽��ʵ�ִ���
	static const int DefaultArraySize = 12; 
	void init(int sz, int *array); 
	// �ڲ����� 
	int _size;
	int *ia; 
};	 
	 
#endif


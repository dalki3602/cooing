#ifndef __ARYLIST_HH__
#define __ARYLIST_HH__

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>

class Array{
    private:
	int type_size; 
	int allocator(unsigned int new_size);

    protected:
	void* ary_list_p;
	int ary_list_size;
    public:
	Array();
	Array(unsigned int size_of_type);
	Array(unsigned int size_of_type, unsigned int list_size);
	Array(const Array&);
	~Array();
	Array& operator=(const Array&);

	virtual void for_each_print()=0;
	int swap_list(unsigned int idx1, unsigned int idx2);
        int get(unsigned int idx);
	int resize(unsigned int new_size);
	void reset();
};

class Int_Array : public Array{
    private:
	int* int_ary_list_p;

    public:
	Int_Array();
	~Int_Array();
	Int_Array(const Int_Array&);
	Int_Array& operator=(const Int_Array&);

        int get(unsigned int idx);
	void put(unsigned int idx, int value);
	int swap_list(unsigned int idx1, unsigned int idx2);
	void for_each_print();
};

#define MAX_STR_SIZE 24

class Str_Array : public Array{
    private:
	char* str_ary_list_p;

    public:
	Str_Array();
	~Str_Array();
	Str_Array(const Str_Array&);
	Str_Array& operator=(const Str_Array&);

        int get(unsigned int idx);
	void put(unsigned int idx, const char* value);
	int swap_list(unsigned int idx1, unsigned int idx2);
	void for_each_print();
};

template <typename t>
class TL_Array : public Array{
    private:
	t* tl_ary_list_p;

    public:
	TL_Array();
	~TL_Array();
	TL_Array(const TL_Array&);
	TL_Array& operator=(const TL_Array&);

        int get(unsigned int idx);
	void put(unsigned int idx, t value);
	int swap_list(unsigned int idx1, unsigned int idx2);
	void for_each_print();
};

#endif /* __ARYLIST_HH__ */

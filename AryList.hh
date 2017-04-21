#ifndef __ARYLIST_HH__
#define __ARYLIST_HH__

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>

#define DEFAULT_ARRAY_SIZE 5
#define PRINT_INTERVAL 10
#define DEBUG

class Array{
    private:
	int type_size; 

	int allocator(unsigned int new_size){ 
	    if(ary_list_size > new_size){
		return 0; 
	    }
		new_size = (ary_list_size*2 > new_size) ? (ary_list_size*2): (new_size); // expanding size
#ifdef DEBUG
		printf("\tallocator: %u -> %u\n", ary_list_size, new_size);
#endif /* DEBUG */

		ary_list_p = realloc(ary_list_p, type_size*new_size); 
		memset((char*)ary_list_p + type_size*ary_list_size, 0, type_size*(new_size-ary_list_size)); 
		ary_list_size = new_size; 
		return 0; 
	}

    protected:
	void* ary_list_p;
	int ary_list_size;
    public:
	Array(){}; 
	Array(unsigned int size_of_type){
	    ary_list_p = NULL;
	    ary_list_size = 0; 
	    type_size = size_of_type;
	    allocator(DEFAULT_ARRAY_SIZE); 
	}
	Array(const Array&);
	virtual ~Array(){
	    if(ary_list_p)
		free(ary_list_p); 
	}
	Array& operator=(const Array&);

	virtual void for_each_print()=0;
	void swap_list(unsigned int idx1, unsigned int idx2){
#ifdef DEBUG
	    printf("func: swap_list(%u,%u)\n", idx1, idx2); 
#endif /* DEBUG */
	}
        int get(unsigned int idx){
#ifdef DEBUG
	    printf("func: get(%u)\n", idx);
#endif /* DEBUG */
	    if(idx > ary_list_size)
	    {
		std::cout << "\t\033[0;31m[ERR]\033[0m get() - invalid idx : " << idx << std::endl; 
		return -1;
	    }
	}
	int resize(unsigned int new_size){
#ifdef DEBUG
	    printf("func: resize(%u)\n", new_size);
#endif /* DEBUG */
	    return allocator(new_size); 
	}
	void reset(){
#ifdef DEBUG
	    printf("func: reset()\n");
#endif /* DEBUG */
	    memset((char*)ary_list_p, 0, type_size*ary_list_size); 
	}
};

class Int_Array : public Array{
    private:
	int* int_ary_list_p;

    public:
	Int_Array() : Array(sizeof(int))
	{
	    int_ary_list_p = (int*)ary_list_p;
	}
	~Int_Array(){}
	Int_Array(const Int_Array&){}
	Int_Array& operator=(const Int_Array&);

        int get(unsigned int idx){
	    if(Array::get(idx) != -1)
	    std::cout << "\t[RET] " << idx << "th value : " << int_ary_list_p[idx] << std::endl;
 	    return 0; 
	}
	void put(unsigned int idx, int value){
	    resize(idx); 
	    int_ary_list_p[idx] = value; 
	}
	void swap_list(unsigned int idx1, unsigned int idx2){
	    int temp;
	    temp=int_ary_list_p[idx1];
	    int_ary_list_p[idx1] = int_ary_list_p[idx2];
	    int_ary_list_p[idx2] = temp; 
	    Array::swap_list(idx1, idx2); 
	}
	void for_each_print(){
#ifdef DEBUG
	    printf("func: for_each_print()\n\t");
#endif /* DEBUG */
	    int v;
	    int cnt=0;
	    for(int i=0; i<ary_list_size; i++){
		v = int_ary_list_p[i]; 
		if(v){
		    if(!(i%PRINT_INTERVAL))
			std::cout << std::endl << "\t";
		    std::cout << "[" << i << "]" << v << " ";
		    cnt++;
		}
	    }
	    if(!cnt)
	    std::cout << "\tlist is empty" << std::endl;
	    else 
	    std::cout << std::endl;
	}
};

#define MAX_STR_SIZE 24

class Str_Array : public Array{
    private:
	char* str_ary_list_p;

    public:
	Str_Array() : Array(MAX_STR_SIZE)
	{
	    str_ary_list_p = (char*)ary_list_p;
	}
	~Str_Array(){}
	Str_Array(const Str_Array&){}
	Str_Array& operator=(const Str_Array&);

        int get(unsigned int idx){
	    if(Array::get(idx) != -1)
	    std::cout << "\t[RET] " << idx << "th value : " << str_ary_list_p+(idx*MAX_STR_SIZE) << std::endl;
 	    return 0; 
	}
	void put(unsigned int idx, const char* value){
	    resize(idx); 
	    strncpy(str_ary_list_p+(idx*MAX_STR_SIZE), value, MAX_STR_SIZE-1); 
	    strncpy(str_ary_list_p+((idx+1)*MAX_STR_SIZE-1), "\0", 1); 
	}
	void swap_list(unsigned int idx1, unsigned int idx2){
	    char* str1 = str_ary_list_p + (idx1*MAX_STR_SIZE);
	    char* str2 = str_ary_list_p + (idx2*MAX_STR_SIZE);
	    char temp[MAX_STR_SIZE];
	    strncpy(temp, str1, MAX_STR_SIZE); 
	    strncpy(str1, str2, MAX_STR_SIZE); 
	    strncpy(str2, temp , MAX_STR_SIZE); 
	    Array::swap_list(idx1, idx2); 
	}
	void for_each_print(){
#ifdef DEBUG
	    printf("func: for_each_print()\n\t");
#endif /* DEBUG */
	    char* v; 
	    for(int i=0; i<ary_list_size; i++){
		v = str_ary_list_p+(i*MAX_STR_SIZE);
		if(v[0]){
		    if(!(i%PRINT_INTERVAL))
			std::cout << std::endl << "\t";
		    std::cout << "[" << i << "]" << v << " ";
		}
	    }
	    std::cout << std::endl;
	}
};

#endif /* __ARYLIST_HH__ */

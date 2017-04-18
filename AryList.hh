#ifndef __ARYLIST_HH__
#define __ARYLIST_HH__

#include <cstdlib>
#include <iostream>
#include <cstring>

#define DEFAULT_ARRAY_SIZE 5

class ArrayList{
    private:
	int type_size; 

	int allocator(unsigned int new_size){ 
	    if(ary_list_size > new_size){
		return 0; 
	    }
		new_size = (ary_list_size*2 > new_size) ? (ary_list_size*2): (new_size); // expanding size
	        std::cout << "allocator " << ary_list_size << "-> " << new_size << std::endl; 

		ary_list_p = realloc(ary_list_p, type_size*new_size); 
		memset(ary_list_p + type_size*ary_list_size, 0, type_size*(new_size-ary_list_size)); 
		ary_list_size = new_size; 
		return 0; 
	}

    protected:
	void* ary_list_p;
	int ary_list_size;
    public:
	ArrayList(){}; 
	ArrayList(unsigned int size_of_type){
	    ary_list_p = NULL;
	    ary_list_size = 0; 
	    type_size = size_of_type;
	    allocator(DEFAULT_ARRAY_SIZE); 
	}
	ArrayList(const ArrayList&){}
	virtual ~ArrayList(){
	    if(ary_list_p)
		free(ary_list_p); 
	}
	ArrayList& operator=(const ArrayList&){}

	int resize(unsigned int new_size){
	    return allocator(new_size); 
	}
	virtual void for_each_print()=0;
};

class Int_ArrayList : public ArrayList{
    private:
	int* int_ary_list_p;

    public:
	Int_ArrayList() : ArrayList(sizeof(int))
	{
	    int_ary_list_p = (int*)ary_list_p;
	}
	~Int_ArrayList(){}
	Int_ArrayList(const Int_ArrayList&){}
	Int_ArrayList& operator=(const Int_ArrayList&);

        int get(unsigned int idx){
	    if(idx > ary_list_size)
	    {
		std::cout << "[ERR] invalid idx : " << idx << std::endl; 
		return -1;
	    }

	    std::cout << "[RET] " << idx << "th value : " << int_ary_list_p[idx] << std::endl;
	   
 	    return 0; 
	}
	void put(unsigned int idx, int value){
	    resize(idx); 
	    int_ary_list_p[idx] = value; 
	    return; 
	}
	void for_each_print(){
	    for(int i=0; i<ary_list_size; i++){
		std::cout << "[" << i << "]" << int_ary_list_p[i] << " ";
	    }
	    std::cout << std::endl;
	}
};

#define MAX_STR_SIZE 24

class Str_ArrayList : public ArrayList{
    private:
	char* str_ary_list_p;

    public:
	Str_ArrayList() : ArrayList(MAX_STR_SIZE)
	{
	    str_ary_list_p = (char*)ary_list_p;
	}
	~Str_ArrayList(){}
	Str_ArrayList(const Str_ArrayList&){}
	Str_ArrayList& operator=(const Str_ArrayList&);

        int get(unsigned int idx){
	    if(idx > ary_list_size)
	    {
		std::cout << "[ERR] invalid idx : " << idx << std::endl; 
		return -1;
	    }

	    std::cout << "[RET] " << idx << "th value : " << str_ary_list_p+(idx*MAX_STR_SIZE) << std::endl;
	   
 	    return 0; 
	}
	void put(unsigned int idx, const char* value){
	    resize(idx); 
	    strncpy(str_ary_list_p+(idx*MAX_STR_SIZE), value, MAX_STR_SIZE-1); 
	    strncpy(str_ary_list_p+((idx+1)*MAX_STR_SIZE-1), "\0", 1); 
	    return; 
	}
	void for_each_print(){
	    for(int i=0; i<ary_list_size; i++){
		std::cout << "[" << i << "]" << str_ary_list_p+(i*MAX_STR_SIZE) << " ";
	    }
	    std::cout << std::endl;
	}
};

#endif /* __ARYLIST_HH__ */

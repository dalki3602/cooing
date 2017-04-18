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
	ArrayList(){
	}
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

#endif /* __ARYLIST_HH__ */

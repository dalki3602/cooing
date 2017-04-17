#ifndef __ARYLIST_HH__
#define __ARYLIST_HH__

#include <cstdlib>
#include <iostream>

#define DEFAULT_ARRAY_SIZE 5

class ArrayList{
    protected:
	void* ary_list_p;
	int ary_list_size; 
    public:
	ArrayList(){
	    ary_list_size = DEFAULT_ARRAY_SIZE;
       	};
	ArrayList(unsigned int size){
	    ary_list_size = size;
	};
	ArrayList(const ArrayList&){};
	virtual ~ArrayList(){
	    free(ary_list_p); 
	};
	ArrayList& operator=(const ArrayList&);

	virtual int ary_resize(unsigned int new_size)=0;
	virtual void for_each_print()=0;
};

#endif /* __ARYLIST_HH__ */

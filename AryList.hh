#ifndef __ARYLIST_HH__
#define __ARYLIST_HH__

#include <cstdlib>
#include <iostream>

#define DEFAULT_ARRAY_SIZE 5

class ArrayList{
    protected:
	int ary_list_size; 
    public:
	void* ary_list_p;
	ArrayList();
	ArrayList(unsigned int size);
	ArrayList(const ArrayList&);
	virtual ~ArrayList();
	ArrayList& operator=(const ArrayList&);

	virtual int ary_resize(unsigned int new_size)=0;
        virtual void* ary_get_index(unsigned int idx)=0;
	virtual void ary_put_index(unsigned int idx, void* vlaue)=0;
};

#endif /* __ARYLIST_HH__ */

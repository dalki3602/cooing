#include "AryList.hh"

class Int_ArrayList : public ArrayList{
  public:
	Int_ArrayList(){
	    ary_list_size = DEFAULT_ARRAY_SIZE;
	    int malloc_size = sizeof(int)*ary_list_size;
	    ary_list_p = malloc(malloc_size); 
	};
	Int_ArrayList(unsigned int size){
	    ary_list_size = size; 
	    int malloc_size = sizeof(int)*ary_list_size;
	    ary_list_p = malloc(malloc_size); 
	};
	Int_ArrayList(const Int_ArrayList&);
	~Int_ArrayList(){
	    free(ary_list_p); 
	}
	Int_ArrayList& operator=(const Int_ArrayList&);

	int ary_resize(unsigned int new_size){
	    if(ary_list_size < new_size){
		new_size = (ary_list_size*2 > new_size) ? (ary_list_size*2): (new_size);
		std::cout << "ary list size expanded ("<< ary_list_size << " -> " << new_size << ")" << std::endl; 
		ary_list_p = realloc(ary_list_p, sizeof(int)*new_size); 
		if(!ary_list_p)
		    return -1; 
	    }
	    return 0; 
	};
        void* ary_get_index(unsigned int idx){
	    if(idx < ary_list_size)
		return (void*)(((int*)ary_list_p)[idx]); 

	    return NULL;
	}
	void ary_put_index(unsigned int idx, void* value){
	    if(idx >= ary_list_size){
		ary_resize(idx+1); 
	    }
	    int v = *(int*)&value; 
	    ((int*)ary_list_p)[idx] = v; 
	    return; 
	}; 
};

int main(){

    Int_ArrayList ary_list;

    ary_list.ary_put_index(1, (void*)3);


    return 0; 
}


#include "AryList.hh"
#include <cstring>

class Int_ArrayList : public ArrayList{
    private:
	int* int_ary_list_p;

    public:
	Int_ArrayList(){
	    ary_list_p = malloc(sizeof(int)*ary_list_size); 
	    int_ary_list_p = (int*) ary_list_p;
	};
	Int_ArrayList(unsigned int size){
	    ary_list_p = malloc(sizeof(int)*ary_list_size);
	    int_ary_list_p = (int*) ary_list_p;
	};
	~Int_ArrayList(){
	}
	Int_ArrayList(const Int_ArrayList&);
	Int_ArrayList& operator=(const Int_ArrayList&);

	int ary_resize(unsigned int new_size){
	    if(ary_list_size < new_size){
		new_size = (ary_list_size*2 > new_size) ? (ary_list_size*2): (new_size);
		ary_list_p = realloc(ary_list_p, sizeof(int)*new_size); 
		memset(ary_list_p+sizeof(int)*ary_list_size, 0, sizeof(int)*(new_size-ary_list_size)); 
		ary_list_size = new_size; 
		if(!ary_list_p)
		    return -1; 
	    }
	    return 0; 
	};
        int ary_get_index(unsigned int idx){
	    if(idx > ary_list_size)
	    {
		std::cout << "index invalid" << std::endl; 
		return -1;
	    }

 	    return int_ary_list_p[idx]; 
	}
	void ary_put_index(unsigned int idx, int value){
	    if(idx >= ary_list_size){
		ary_resize(idx+1); 
	    }
	    int_ary_list_p[idx] = value; 
	    return; 
	}; 
	void for_each_print(){
	    for(int i=0; i<ary_list_size; i++){
		std::cout << i << " " << int_ary_list_p[i] << std::endl;
	    }
	};
};

int main(){

    Int_ArrayList ary_list;
    ary_list.ary_put_index(2,3);
    ary_list.ary_resize(12); 

    ary_list.for_each_print();


    return 0; 
}


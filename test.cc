#include "AryList.hh"

class Int_ArrayList : public ArrayList{
    private:
	int* int_ary_list_p;

    public:
	Int_ArrayList(unsigned int size_of_type) : ArrayList(size_of_type)
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

int main(){
    int get_idx, idx; 
    Int_ArrayList ary_list(sizeof(int));

    ary_list.put(2,3);
    ary_list.resize(12); 
    ary_list.put(11,100);

    ary_list.get(14);
    ary_list.get(11);

    ary_list.put(12,200);
    ary_list.put(22,300);

    ary_list.for_each_print();

    return 0; 
}


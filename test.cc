#include "AryList.hh"

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

int main(){
    /* int ary */
    Int_ArrayList int_list;

    int_list.put(2,3);
    int_list.resize(12); 
    int_list.put(11,100);

    int_list.get(14);
    int_list.get(11);

    int_list.put(12,200);
    int_list.put(22,300);

    int_list.for_each_print();


    /* string(define max size) ary */
    Str_ArrayList str_list; 
    str_list.put(1,"first test"); 
    str_list.put(2,"Second test"); 
    str_list.put(9,"9th test"); 
    str_list.put(12,"12th test"); 
    str_list.get(9);
    
    str_list.for_each_print();
    str_list.put(10,"12345678901234567890123456789012345678901234567890");
    str_list.for_each_print();

    str_list.put(10,"reset data");
    str_list.for_each_print();

    str_list.put(20,"max_data input!"); 
    str_list.for_each_print();
    return 0; 
}


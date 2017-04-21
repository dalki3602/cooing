#include "AryList.hh"
#include <list>

int main(){
    std::cout << "--------------- Int Array -------------------" << std::endl;
    /* int ary */
    Int_Array int_list;

    int_list.put(2,3);
    int_list.resize(12); 
    int_list.put(11,100);

    int_list.get(14);
    int_list.get(11);

    int_list.put(12,200);
    int_list.put(22,300);

    int_list.for_each_print();

    int_list.swap_list(22,12);
    int_list.for_each_print();

    int_list.reset();
    int_list.for_each_print();

    std::cout << std::endl << "--------------- Str Array -------------------" << std::endl;

    /* string(define max size) ary */
    Str_Array str_list; 
    str_list.put(1,"first test"); 
    str_list.put(2,"Second test"); 
    str_list.put(9,"9th test"); 
    str_list.put(12,"12th test"); 
    str_list.get(9);
    
    str_list.for_each_print();
    str_list.put(10,"12345678901234567890123456789012345678901234567890");
    str_list.for_each_print();

    str_list.swap_list(10,12); 
    str_list.for_each_print();

    str_list.get(21);

    str_list.put(10,"reset data");
    str_list.for_each_print();

    str_list.put(20,"max_data input!"); 
    str_list.for_each_print();

    str_list.reset();
    str_list.for_each_print();

    std::cout << std::endl << "--------------- Array -------------------" << std::endl;
#if 0
    //typedef std::list <Int_Array*> int_ary_list;
    using int_ary_list = std::list <Int_Array*>;
    int_ary_list instance; 
#else
    std::list <Int_Array*> instance;
#endif

    instance.push_front(&int_list);
    instance.push_front(&int_list);

#if 0
    for(int_ary_list::iterator listMyClassIter = instance.begin(); // not int_ary_list.begin()
	        listMyClassIter != instance.end(); 
		    listMyClassIter ++)
    {
	    (*listMyClassIter)->for_each_print();  
    }
#else
   for(Int_Array* i: instance)
    {
	i->for_each_print();  
    }
#endif
    return 0; 
}


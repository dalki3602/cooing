#include "AryList.hh"

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


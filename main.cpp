#include <iostream>
#include "Date.h"
#include "TemporaryEmployee.h"
#include "PermanentEmployee.h"
#include "CircularArrayLinkedList.h"
#include "DoubleDynamicLinkedList.h"

using namespace std;
int main(){

    TemporaryEmployee temporaryEmployee(10,"can","olcer","elif",15.2, Date(20,06,2001),Date(29,11,2021),0);
    TemporaryEmployee temporaryEmployee1(14,"zub","civelek","bos",7.8, Date(04,06,2001),Date(30,11,2021),5);
    TemporaryEmployee temporaryEmployee2(9,"yasin","komur","slm",1.3, Date(13,02,1999),Date(7,5,2020),8);
    TemporaryEmployee temporaryEmployee3(11,"selahattin","olcer","elif",7.6,Date(20,06,2001),Date(30,11,2020),0);
    TemporaryEmployee temporaryEmployee4(15,"zulfikar","civelek","mrb",2.1,Date(4,8,2005),Date(10,12,2020),8);
    TemporaryEmployee temporaryEmployee5(13,"elif","olcer","can",13.5,Date(10,07,2001),Date(25,8,20),0);

    CircularArrayLinkedList circularList = CircularArrayLinkedList();
    circularList.add(&temporaryEmployee);
    circularList.add(&temporaryEmployee1);
    circularList.add(&temporaryEmployee2);
    circularList.add(&temporaryEmployee3);
    circularList.add(&temporaryEmployee4);
    circularList.add(&temporaryEmployee5);

    circularList.printList();

    TemporaryEmployee temporaryEmployee6(14,"zub","civelek","bos",7.8, Date(04,06,2001),Date(30,11,2021),5);
    cout<<circularList.contains(&temporaryEmployee6);
    circularList.add(&temporaryEmployee6);


    cout<<"*****************"<<endl;
    circularList.printList();





    return 0;
}
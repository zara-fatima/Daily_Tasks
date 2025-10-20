#include "LSLL.h"
#include<iostream>
using namespace std;

int main(){
 LSLL<int> list1;

    list1.insertAtHead(10);
    list1.insertAtTail(20);
    list1.insertAtTail(30);
    list1.insertAtTail(11);
    list1.insertAtTail(20);
    list1.insertAtTail(33);

    list1.removeDuplicates();
    list1.display();
}
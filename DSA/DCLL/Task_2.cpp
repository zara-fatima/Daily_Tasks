#include<iostream>
#include "DCLL.h"
using namespace std;
int main()
{
    CDLinkedList<int> l1;
    CDLinkedList<int> l2;
    CDLinkedList<int> l3;
    l1.insertAtHead(2);
    l1.insertAtHead(3);
    l1.insertAtHead(4);
    l1.insertAtHead(5);
    l1.insertAtHead(6);
    l1.splitList(l2,l3);
    l2.display();
    l3.display();
    return 0;
}
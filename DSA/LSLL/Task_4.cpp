#include "LSLL.h"
#include<iostream>
using namespace std;

// void reverse(){
//     Node<int>* prv=0;
//     Node<int>* temp=head;
// }

int main(){
    LSLL<int> list1;

    list1.insertAtHead(10);
    list1.insertAtTail(20);
    list1.insertAtTail(30);
    list1.reverse();

}
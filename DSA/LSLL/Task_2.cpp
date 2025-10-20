#include "LSLL.h"
#include<iostream>
using namespace std;

// void combine(LSLL<int>& list1, LSLL<int>& list2){
//     Node<int>* temp = list1->head;
//     while(temp!=0){
//         temp=temp->next;
//     }
//     t1->
// }

int main(){
    LSLL<int> list1;

    list1.insertAtHead(10);
    list1.insertAtTail(20);
    list1.insertAtTail(30);

     LSLL<int> list2;

    list2.insertAtHead(1);
    list2.insertAtTail(2);
    list2.insertAtTail(3);

    list1.combine(list1, list2);
    
}
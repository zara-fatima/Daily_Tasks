#include "LSLL.h"
#include<iostream>
using namespace std;
int main()
{
    bool res; 
    LSLL<int> list; int val=0;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    res=list.removeKthNode(3,val);
    if(res==1){
    cout<<"The 3rd node is removed which is: "<<val<<endl;
    }
    else
    cout<<"Not removed"<<endl;
    list.display();
}
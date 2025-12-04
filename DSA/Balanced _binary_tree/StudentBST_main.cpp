#include<iostream>
#include"StudentBST.h"
int main()
{
    StudentBST obj;
    obj.insert(01,"Zara",3.4);
    obj.insert(02,"Noor",3.6);
    obj.insert(03,"Maha",3.7);
    obj.insert(04,"Sara",3.8);

    bool res=obj.search(4);
    cout<<endl<<res;
    cout<<"Inorder: "<<endl;
    obj.inOrder();

    cout<<"Range: "<<endl;
    obj.inRange(3.3,3.6);

    obj.deleteMethod(3);
    cout<<"Inorder after one deletion: "<<endl;
    obj.inOrder();
}
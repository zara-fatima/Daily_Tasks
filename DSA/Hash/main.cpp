#include"Hash.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of Hash Table: ";
    cin>>n;
    HashTable h(n);
    cout<<"1. Insert name."<<endl;
    cout<<"2. Search for a name."<<endl;
    cout<<"3. Remove a name."<<endl;
    cout<<"4. Display a hash Table name."<<endl;
    cout<<"5. Display loadfactor."<<endl;
    cout<<"6. Exit."<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Enter your choice: ";
        cin>>n;
    if(n==1)
    {
        h.insert("Zara");
        h.insert("Noor");
        h.insert("Maha");
        h.insert("Maha");
    }
    else if(n==2)
    {
        bool res=h.search("Zara");
        cout<<res<<endl;
    }
    else if(n==3)
    {
        h.remove("Maha");
        h.display();

    }
    else if(n==4)
    {
        h.display();
    }
    else if(n==5)
    {
        double lf=h.loadFactor();
        cout<<endl<<"Load factor: "<<lf;
    }
    }
    
    
    return 0;
}
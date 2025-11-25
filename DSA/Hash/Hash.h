#include<iostream>
#include<string>
using namespace std;

class HashTable 
{
private:
 string* table;
 int s; // Table size
 int n; // Current number of elements
public:
 HashTable(int size)
 {
    s=size;
    n=0;
    table=new string[size];
    for (int i = 0; i < size; i++)
    {
        table[i]="?";
    }
    
 }
 ~HashTable()
 {
    delete table;
 }
 bool isEmpty() 
 {
    if (this->n!=0)
    {
        return false;
    }
    return true;
 }
 bool isFull()
 {
    if (this->n==(s-1))
    {
        return false;
    }
    return true;
 }
 double loadFactor()
 {
    return double(n)/double(s);
 }
 int getHashValue(string name)
 {
    int sum=0;
    for (int i = 0; i < name.length(); i++)
    {
        char c=name[i];
        sum=sum+c;
    }
    return sum%s;
 }
 bool insert(string name)
 {

    if(s==n) return false;
    int index=getHashValue(name);
    int indx=index;
    if(table[index]=="?")
    {
        table[index]=name;
        n++;
        return true;
    }
    else
    {
        for (int i = index; i < s; i++)
        {
            cout<<"Went to index: "<<i<<endl;
            if(table[indx]=="?")
            {
                cout<<"Inserted at: "<<i<<endl;
                table[indx]=name;
                n++;
                return true;
            }
            indx++;
        }
        
    }
    for (int i = 0; i < index; i++)
    {
        cout<<"Went to index: "<<i<<endl;
        if(table[i]=="?")
        {
            cout<<"Inserted at: "<<i<<endl;
            table[i]=name;
            n++;
            return true;
        }
        
    }
    return false;
 }
 bool search(string name)
 {
    int index=getHashValue(name);
    int indx=index;
    if (table[index]==name)
    {
        return true;
    }
    else
    {
        for (int i = index; i < s; i++)
        {
            cout<<"Went to index: "<<i<<endl;
            if(table[indx]==name)
            {
                cout<<"Found at: "<<i<<endl;
                return true;
            }
            indx++;
        }
    }
    for (int i = 0; i < index; i++)
    {
        cout<<"Went to index: "<<i<<endl;
        if(table[i]==name)
        {
            cout<<"Found at: "<<i<<endl;
            return true;
        }
        
    }
    return false;
 }
 bool remove(string name)
 {
   
    int index=getHashValue(name);
    int indx=index;
    if (table[index]==name)
    {
        table[index]="?";
        n--;
        return true;
    }
    else
    {
        for (int i = index; i < s; i++)
        {
            if(table[indx]==name)
            {
                table[index]="?";
                n--;
                return true;
            }
            indx++;
        }
    }
    for (int i = 0; i < index; i++)
    {
        if(table[i]==name)
        {
            table[index]="?";
            n--;
            return true;
        }
        
    }
    return false;
 }
 void display()
 {
    for (int i = 0; i < s; i++)
    {
        if (table[i]=="?")
        {
            cout<<i<<". EMPTY"<<endl;
        }
        else
        {
            cout<<i<<". "<<table[i]<<endl;
        }
    }
 }

//  int indexOfFruit(string fruit)
//  {
//     int sum=0;
//     for (int i = 0; i < 2; i++)
//     {
//         char c=fruit[i];
//         sum=sum+c;
//     }
//     return sum%s;
//  }



};
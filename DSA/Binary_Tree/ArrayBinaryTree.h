#ifndef zara_ArrayBinaryTree
#define zara_ArrayBinaryTree

#include <iostream>
#include <cmath>
#include <string>
#include"Queue.h"
#include"Stack.h"
using namespace std;

template <typename t>
class BinaryTree
{
    private:
    int height;
    t* data;
    bool* status;
    void preorderHelper(int i);
    void postorderHelper(int i);
    void inorderHelper(int i);
    int size()
    {
        return int((pow(2,height)-1));
    }

    public:
    BinaryTree(int h);
    void setRoot(t r);
    t getRoot();
    void setLeftChild(t p, t v);
    void setRightChild(t p, t v);
    int search(t p);
    t getParent(t node);
    void display();   //Level order
    void preorder();
    void postorder();
    void inorder();
    void remove(t v);
    ~BinaryTree();
    void displayAncestor(t node);
    void displayDescendent(t node);
    int getheight();
    void displayLevel(int level);
    int findLevel(t node);
    void displayParenthesizedView();
};

template <typename t>
void BinaryTree<t>::displayParenthesizedView()
{

}

template <typename t>
int BinaryTree<t>::findLevel(t node)
{
    int index=-1;
    for (int i = 0; i < this->size(); i++)
    {
        if (data[i]==node)
        {
            index=i;
        }
        
    }
    if(index==-1)
    {
        cout<<"Value not matched";
    }
    else
    {
        for (int i = 0; i < this->size(); i++)
        {
            if((pow(2,i)-1) < index && (pow(2,i+1)-1) > index)
            {
                index=i;
                break;
            }
        }
        
    }
    return index;
    
}

template <typename t>
void BinaryTree<t>::displayLevel(int level)    //Node at particular level
{
    int start=int((pow(2,level)-1));
    int end=int((pow(2,level+1)-1));
    for ( int i = start; i < end; i++)
    {
        if (status[i]==true)
        {
            cout<<data[i]<<" ";
        }
        
    }
    
}

template <typename t>
int BinaryTree<t>::getheight()
{
    return height;
}

template <typename t>
void BinaryTree<t>::displayDescendent(t node)      //Descendents
{
    int i=search(node);
    preorderHelper(i);
}

template <typename t>
void BinaryTree<t>::displayAncestor(t node)      //Ancestors
{
    t r=getRoot();
    while (node!=r)
    {
        node=getParent(node);
        cout<<node<<"  ";
    }
    
}

template <typename t>
t BinaryTree<t>::getParent(t node)    //Get parent
{
    int parent_idx=-1;
    for (int i = 0; i < this->size(); i++)
    {
        if (status[i]==true && data[i]==node)
        {
            parent_idx=(i-1)/2;
            return data[parent_idx];
        }
        
    }
    if (parent_idx<0)
    {
        cout<<"Parent does not exist.";
    }
    
}

template <typename t>       //Parametrized constructor 
BinaryTree<t>::BinaryTree(int h)
{
    height=h;
    data= new t[this->size()];
    status = new bool[this->size()];
    for(int i=0; i<this->size(); i++)
    {
        status[i]=false;
    }
}

template <typename t>        //Set Root
void BinaryTree<t>::setRoot(t r)
{
    data[0]=r;
    status[0]=true;
}

template <typename t>           //Set Left Child
void BinaryTree<t>::setLeftChild(t p, t v)
{
    for (int i = 0; i < this->size(); i++)
    {
        if(status[i]==true && data[i]==p)
        {
            if (2*i+1 < this->size())
            {
                data[2*i+1]=v;
                status[2*i+1]=true;
            }
            
        }
    }
    
}

template <typename t> 
t BinaryTree<t>::getRoot()   //Get root
{
    return data[0];
}

template <typename t>           //Set Right Child
void BinaryTree<t>::setRightChild(t p, t v)
{
    for (int i = 0; i < this->size(); i++)
    {
        if(status[i]==true && data[i]==p)
        {
            if (2*i+2 < this->size())
            {
                data[2*i+2]=v;
                status[2*i+2]=true;
            }
            
        }
    }
    
}

template <typename t>
int BinaryTree<t>::search(t p)
{
    for (int i = 0; i < this->size(); i++)
    {
        if(status[i]==true && data[i]==p)
        return i;
    }
    return 0;
    
}

template <typename t>
void BinaryTree<t>::display()     //Level order display
{
    for (int i = 0; i < this->size(); i++)
    {
        cout<<data[i]<<"  ";
    }
    
}

// Public function (just calls the helper)
template <typename T>
void BinaryTree<T>::preorder()
{
    preorderHelper(0);
}

// Private helper function for preorder
template <typename t>
void BinaryTree<t>::preorderHelper(int i)
{
    if (i >= this->size() || status[i] == false)
        return;
    if(i%2!=0)
    cout<<"( ";
    cout << data[i]<<" ";    
    preorderHelper(2*i + 1);

    preorderHelper(2*i + 2);
    if(i%2==0)
    cout<< ")";
}

// Public function (just calls the helper)
template <typename T>
void BinaryTree<T>::postorder()
{
    postorderHelper(0);
}

// Private helper function for postorder
template <typename t>
void BinaryTree<t>::postorderHelper(int i)
{
    if (i >= this->size() || status[i] == false)
        return;
    postorderHelper(2*i+1);
    postorderHelper(2*i+2);
    cout<<data[i]<<" ";
}

// Public function (just calls the helper)
template <typename T>
void BinaryTree<T>::inorder()
{
    inorderHelper(0);
}

// Private helper function for inorder
template <typename t>
void BinaryTree<t>::inorderHelper(int i)
{
    if (i >= this->size() || status[i] == false)
        return;
    inorderHelper(2*i+1);
    cout<<data[i]<<" ";
    inorderHelper(2*i+2);
}

template <typename t>
void BinaryTree<t>::remove(t v)
{
    for (int i = 0; i < this->size(); i++)
    {
        if(data[i]==v)
        status[i]=false;
    }
    
}

// template <typename t>
// void BinaryTree<t>::remove(t v)
// {
//     int total = (1 << height) - 1;
//     for (int i = 0; i < total; i++)
//     {
//         if (status[i] && data[i] == v)
//         {
//             // recursively clear all descendants
//             queue<int> q;
//             q.push(i);
//             while (!q.empty()) {
//                 int idx = q.front(); q.pop();
//                 if (idx < total && status[idx]) {
//                     status[idx] = false;
//                     q.push(2*idx + 1);
//                     q.push(2*idx + 2);
//                 }
//             }
//             break;
//         }
//     }
// }


template <typename t>
BinaryTree<t>::~BinaryTree()
{
    delete[] data;
    delete[] status;
}


#endif

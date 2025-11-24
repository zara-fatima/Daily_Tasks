#ifndef _Zara_Stack
#define _Zara_Stack

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <typename t>
class Stack
{
    private:
    t * data;
    int capacity;
    int top;

    public:
    Stack(int c);
    Stack(Stack & s2);
    ~Stack();
    int getTop();
    void push(t value);
    t pop();
    t stackTop();
    bool isEmpty();
    bool isFull();
    Stack operator = (const Stack& other);
};

template <typename t>
Stack<t>::Stack(int c)
{
    if (c > 0)
    {
        capacity = c;
        top = 0;
        data = new t[c];
    }
    else
    {
        throw ("stack capacity must be > 0");
    }
}
template <typename t>
Stack<t>::Stack(Stack<t> &s2)
{
    this->capacity=s2.capacity;
    this->top=s2.top;
    data=new t [s2.capacity];
    if (top!=0)
    {
        for(int i=0;i<top;i++)
        {
            data[i]=s2.data[i];
        }
    }

}
template <typename t>
Stack <t>:: ~Stack()
{
    delete[] this->data; 
}
template <typename t>
int Stack<t> ::getTop()
{
    return top;
}
template <typename t>
void Stack <t>::push(t value)
{
    if(! isFull())
    {
        data[top]=value;
        top++;
    }
    else{
        throw ("Stack is full");
    }
}
template <typename t>
t Stack<t> ::pop()
{
    if(! isEmpty())
    {
        top--;
        return data[top];
    }
    else 
    {
        throw ("Stack is empty");
        
    }
}
template <typename t>
t Stack<t> ::stackTop()
{
    if (top !=0)
    {
        return data[top-1];
    }
    else
    {
        throw("Stack is empty");
        
    }
}
template <typename t>
bool Stack <t>::isEmpty()
{
    bool empty=false;
    if(top==0)
    {
        empty=true;
    }
    return empty;
}
template <typename t>
bool Stack<t> ::isFull()
{
    bool full =false;
    if(top==capacity)
    {
         full =true;
    }
    return full;
}
template <typename t>
Stack<t> Stack<t>:: operator =(const Stack<t> &other)
{
    if(this!= & other)
    {
        delete[] data;
        this->capacity=other.capacity;
        this->top=other.top;
        this->data=new t [capacity];
        if(top!=0)
        {
            for(int i=0;i<capacity;i++)
            {
                this->data[i]=other.data[i];
            }
        }
    }
    return *this;
}

#endif
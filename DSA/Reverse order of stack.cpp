#include <iostream>
#include <string>
#include <cstdlib> //for exit 
//Reverse the order of elements in stack S
//Using two stacks

using namespace std;
class Stack
{
	private:
    char* data;
    int capacity;
    int top;
    
    public:
	Stack(int c)
    {
       if (c > 0)
        {
        capacity = c;
        top = 0;
        data = new char[c];
        }
        else
        {
        throw ("stack capacity must be > 0");
        }
    }
Stack (Stack &s2)
{
    this->capacity=s2.capacity;
    this->top=s2.top;
    data=new char [s2.capacity];
    if (top!=0)
    {
        for(int i=0;i<top;i++)
        {
            data[i]=s2.data[i];
        }
    }

}
~Stack()
{
    delete[] this->data; 
}
int getTop()
{
    return top;
}
void push(char value)
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
char pop()
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
char stackTop()
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
bool isEmpty()
{
    bool empty=false;
    if(top==0)
    {
        empty=true;
    }
    return empty;
}
bool isFull()
{
    bool full =false;
    if(top==capacity)
    {
         full =true;
    }
    return full;
}

Stack operator =(const Stack &other)
{
    if(this!= & other)
    {
        delete[] data;
        this->capacity=other.capacity;
        this->top=other.top;
        this->data=new char[capacity];
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
};

int main()
{
	Stack s1(5); Stack s2(5); 
	Stack s3(5);
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s1.push('d');
	s1.push('e');
	for(int i=1; i <= 5; i++)
		s2.push(s1.pop());
	for(int i=1; i <= 5; i++)
		s1.push(s2.pop());
	for(int i=1; i <= 5; i++)
		s1.push(s3.pop());
	for(int i=1; i <= 5; i++)
		cout<<s1.pop()<<endl;
}

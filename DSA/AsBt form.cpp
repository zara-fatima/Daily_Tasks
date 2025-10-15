#include <iostream>
#include <string>
#include <cstdlib> //for exit 

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

bool in_form(string s)
{
	Stack st(10);
	bool res=true, bstart=false; 
	for(int i=0; i < s.length(); i++)
	{
		if(s[i]=='a')
		{
			if(bstart)
			   return false;
			st.push(s[i]);
		}
		else if(s[i]=='b')
		{
			bstart=true;
			st.push(s[i]);
		}
		else 
		  return false;
	}
	return res;
}

int main()
{
	string str;
	cout<<"Enter a string: ";
	cin>>str;
	bool res=in_form(str);
	if(res)
	cout<<"It is in the a^s b^t form.";
	else
	cout<<"It is not in the form.";
}

#ifndef _Zara_Fatima_Queue
#define _Zara_Fatima_Queue

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <typename t>
class Queue
{
    private:
    t * data;
    int capacity;
    int noOfelements;
    int front;
    int rear;

    public:
    Queue(int c=10);
    Queue(const Queue<t>& q2);
    ~Queue();
    void enqueue(t value);
    t dequeue();
    void resize();
    bool isEmpty();
    bool isFull();
    void display();
    Queue<t>& operator = (const Queue<t>& other);
};

template <typename t>
Queue<t>::Queue(int c)    //Parametrized constructor
{
	if (c > 0)
    {
        capacity = c;
        front=0;
        rear=0;
        noOfelements=0;
        data = new t[c];
    }
    else
    {
        throw ("Queue capacity must be > 0");
    }
}

template <typename t>
Queue<t>::Queue(const Queue<t>& q2)       //Copy constructor
{
	front=q2.front;
	rear=q2.rear;
	capacity=q2.capacity;
	noOfelements=q2.noOfelements;
	data = new t[capacity];
	for(int i=0; i < noOfelements; i++)
	{
		data[(i+front)%capacity]=q2.data[(i+front)%capacity];
	}
}

template <typename t>
Queue<t>:: ~Queue()      //Destructor
{
    delete[] this->data; 
} 

template <typename t>
void Queue<t>:: enqueue(t value)     //Enqueue
{
	if(!isFull())
	{
		data[rear]=value;
		noOfelements++;
		rear=(rear+1)%capacity;
	}
	else
    {
       resize();    // auto-resize
       enqueue(value);
    }
}

template <typename t>
t Queue<t>:: dequeue()            //Dequeue
{
	if(!isEmpty())
	{
		t e=data[front];
		front=(front+1)%capacity;
		noOfelements--;
		return e;
	}
	else
    {
       throw runtime_error("Queue is empty, cannot dequeue");
    }
}

template <typename t>
void Queue<t>:: resize()             //Resize
{
	t* data1= new t[capacity*2];
	for(int i=0; i < noOfelements; i++)
	{
		data1[i]=data[(i+front)%capacity];
	}
	delete[] data;
	data=data1;
	capacity=capacity*2;
	front=0;
	rear=noOfelements;
}

template <typename t>
bool Queue<t>:: isFull()        //isFull
{
	bool full=false;
    if(noOfelements==capacity)
    {
        full =true;
    }
    return full;
}

template <typename t>
bool Queue<t>:: isEmpty()      //isEmpty
{
	bool res=false;
	if(noOfelements==0)
	{
		res=true;
	}
	return res;
}

template <typename t>           //Display
void Queue<t>:: display()
{
	for(int i=0; i < noOfelements; i++)
	{
		cout<<data[(i+front)%capacity]<<"  ";
	}
}

template <typename t>
Queue<t>& Queue<t>::operator=(const Queue<t>& other)
{
    if (this != &other)   // protect against self-assignment
    {
        delete[] data;

        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        noOfelements = other.noOfelements;

        data = new t[capacity];
        for (int i = 0; i < noOfelements; i++)
        {
            data[(i+front) % capacity] = other.data[(i+front) % capacity];
        }
    }
    return *this;
}

#endif
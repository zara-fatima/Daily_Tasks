#include <iostream>
using namespace std;

template <class T>
Node<T>::Node()
{
    data = 0;
    next = NULL;
}

template <class T>
Node<T>::Node(T val)
{
    data = val;
    next = NULL;
}

template <class T>
LSLL<T>::LSLL()
{
    head = NULL;
}

template <class T>
Node<T>* LSLL<T>::getHead(){
    return this->head;
}

template <class T>
void LSLL<T>::insertAtHead(T val)
{
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
}

template <class T>
void LSLL<T>::insertAtTail(T val)
{
    Node<T>* newNode = new Node<T>(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node<T>* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


template <class T>
void LSLL<T>::insertBefore(T key, T val)
{
    if (head == NULL)
    {
        cout << "List empty hai.\n";
        return;
    }

    if (head->data == key)
    {
        insertAtHead(val);
        return;
    }

    Node<T>* prev = NULL;
    Node<T>* temp = head;

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Key " << key << " not found.\n";
        return;
    }

    Node<T>* newNode = new Node<T>(val);
    prev->next = newNode;
    newNode->next = temp;
}

template <class T>
void LSLL<T>::insertAfter(T key, T val)
{
    if (head == NULL)
    {
        cout << "List empty hai.\n";
        return;
    }

    Node<T>* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Key " << key << " not found.\n";
        return;
    }

    Node<T>* newNode = new Node<T>(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

template <class T>
void LSLL<T>::removeAtHead()
{
    if (head == NULL)
    {
        cout << "List empty hai.\n";
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template <class T>
void LSLL<T>::removeAtTail()
{
    if (head == NULL)
    {
        cout << "List empty hai.\n";
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node<T>* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

template <class T>
void LSLL<T>::remove(T val)
{
    if (head == NULL)
    {
        cout << "List empty hai.\n";
        return;
    }

    if (head->data == val)
    {
        removeAtHead();
        return;
    }

    Node<T>* temp = head;
    Node<T>* prev = NULL;

    while (temp != NULL && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value " << val << " not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}

template <class T>
void LSLL<T>::removeBefore(T key)
{
    if (head == NULL || head->data == key)
    {
        cout << "Head ke pehle kuch nahi hota.\n";
        return;
    }

    if (head->next == NULL)
    {
        cout << "Only one node hai.\n";
        return;
    }

    Node<T>* prevPrev = NULL;
    Node<T>* prev = head;
    Node<T>* temp = head->next;

    while (temp != NULL && temp->data != key)
    {
        prevPrev = prev;
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Key " << key << " not found.\n";
        return;
    }

    if (prevPrev == NULL)
    {
        removeAtHead();
        return;
    }

    prevPrev->next = temp;
    delete prev;
}

template <class T>
void LSLL<T>::removeAfter(T key)
{
    if (head == NULL)
    {
        cout << "List empty hai.\n";
        return;
    }

    Node<T>* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Key " << key << " not found.\n";
        return;
    }

    if (temp->next == NULL)
    {
        cout << "Key ke baad koi node nahi hai.\n";
        return;
    }

    Node<T>* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

template <class T>
int LSLL<T>::search(T key)
{
    Node<T>* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

template <class T>
void LSLL<T>::update(T key, T val)
{
    if (head == NULL)
    {
        cout << "List empty hai.\n";
        return;
    }

    Node<T>* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            temp->data = val;
            return;
        }
        temp = temp->next;
    }

    cout << "Key " << key << " not found.\n";
}

template <class T>
int LSLL<T>::countNodes()
{
    int count = 0;
    Node<T>* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

template <class T>
void LSLL<T>::display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node<T>* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T>
LSLL<T>::~LSLL()
{
    Node<T>* temp = head;
    while (temp != NULL)
    {
        Node<T>* delNode = temp;
        temp = temp->next;
        delete delNode;
    }
    head = NULL;
}

template <class T>
bool LSLL<T>::removeKthNode(int key, int& val)
{
    if(head==0){
        return 0;
    }
    else if(key==1){
        Node<T>* temp=head;
        val=temp->data;
        head=head->next;
        delete temp;
        return 1;
    }
    else{
        int count=2;
        Node<T>* temp=head->next;
        Node<T>* prv=head;
            while (temp!=0)
            {
                if(count==key)
                {
                    prv->next=temp->next;
                    val=temp->data;
                    delete temp;
                    return 1;
                }
                prv=temp;
                temp=temp->next;
                count++;
            }
            
        }
}

template <class T>
void LSLL<T>::combine(LSLL& t1, LSLL& t2){
    Node<int>* temp = t1.head;
    while(temp!=NULL){
        temp=temp->next;
    }
    temp=t2.head;
    t1.display();
}

template <class T>
void LSLL<T>::reverse(){
    Node<int>* prv=0;
    Node<int>* nextNode=0;
    Node<int>* temp=head;
    while(temp!=NULL){
        nextNode=temp->next;
        temp->next=prv;
        prv=temp;
        temp=nextNode;
    }
    head=prv;
    display();
}
template <class T>
void LSLL<T>::removeDuplicates()
{
    Node<T>* curr=head;
    while (curr!=NULL)
    {
        Node<T>* temp=curr;
        while (temp->next!=NULL)
        {
            if(temp->next->data==curr->data){
                Node<T>* dup=temp->next;
                temp->next=temp->next->next;
                delete dup;
            }
            else{
                temp=temp->next;
            }
        }
        curr=curr->next;
        
    }
    
}


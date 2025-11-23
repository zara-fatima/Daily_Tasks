#ifndef zara_double_linked_list
#define zara_double_linked_list

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

template <typename t>
class DNode
{
public:
    t data;
    DNode *next;
    DNode *prev;

    DNode()
    {
        next = prev = NULL;
    }
    DNode(t val)
    {
        data = val;
        next = prev = NULL;
    }
};

template <typename t>
class CDLinkedList
{
private:
    DNode<t> *head;

public:
    CDLinkedList()
    {
        head = NULL;
    }
    ~CDLinkedList() ;

    void insertAtHead(t val);
    void insertAtTail(t val);

    void removeAtHead();
    void removeAtTail();
    void remove(t val);

    bool search(t key);
    void update(t key, t val);
    int countNodes();
    void display();
    DNode<int>* middleNode();
    void splitList (CDLinkedList& leftHalf, CDLinkedList& rightHalf);
    void merge(CDLinkedList<int>& other);
};

template <typename t>
DNode<int>* CDLinkedList<t>::middleNode() {
    if (!head) throw runtime_error("Empty List");
    DNode<int>* slow = head;
    DNode<int>* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename t>
void CDLinkedList<t>::splitList (CDLinkedList& leftHalf, CDLinkedList& rightHalf)
{
    DNode<int> *temp=head;
    DNode<int> *mid;
    mid=this->middleNode();
    leftHalf.head=head;
    rightHalf.head=mid->next;
    head->prev=rightHalf;
    rightHalf->head=head->prev->next;
}

template <typename t>
CDLinkedList<t>::~CDLinkedList()
{
    if (head == NULL)
        return;

    DNode<t>* temp = head;
    DNode<t>* nextNode = nullptr;

    // break the circular link first
    head->prev->next = NULL;

    while (temp != NULL)
    {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
}

template <typename t>
void CDLinkedList<t>::insertAtTail(t val)
{
    if (head == NULL)
    {
        cout << "No head exists, so inserting as first node.\n";
        insertAtHead(val);
        return;
    }

    DNode<t> *newnode = new DNode<t>(val);
    DNode<t> *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = head;
    head->prev = newnode;
}


template <typename t>
void CDLinkedList<t>::removeAtHead()
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    DNode<t> *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    DNode<t> *node_to_del = head;
    head = head->next;
    temp->next = head;
    head->prev = temp;
    delete node_to_del;
}


template <typename t>
void CDLinkedList<t>::removeAtTail()
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    DNode<t> *tail = head;
    while (tail->next != head)
    {
        tail = tail->next;
    }

    DNode<t> *prevNode = tail->prev;
    prevNode->next = head;
    head->prev = prevNode;
    delete tail;
}


template <typename t>
void CDLinkedList<t>::remove(t val)
{
    if (head == NULL)
    {
        return;
    }

    // single node case
    if (head->next == head && head->data == val)
    {
        delete head;
        head = NULL;
        return;
    }

    DNode<t> *temp = head;
    do
    {
        if (temp->data == val)
        {
            if (temp == head)
            {
                removeAtHead();
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

template <typename t>
bool CDLinkedList<t>::search(t key)
{
    if (head == NULL)
    {
        return false;
    }

    DNode<t> *temp = head;
    do
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
}


template <typename t>
void CDLinkedList<t>::update(t key, t val)
{
    if (head == NULL)
    {
        return;
    }

    DNode<t> *temp = head;
    do
    {
        if (temp->data == key)
        {
            temp->data = val;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value not found, so nothing is updated.\n";
}


template <typename t>
int CDLinkedList<t>::countNodes()
{
    int count = 0;
    if (head == NULL)
    {
        return count;
    }

    DNode<t> *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}
template <typename t>
void CDLinkedList<t>:: display()
{
    DNode <t>* temp=head;
    if(head==nullptr)
    {
        return;
    }
    while(temp->next != head)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<temp->data;
}

#endif
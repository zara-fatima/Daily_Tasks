#ifndef LSLL_H
#define LSLL_H

#include <iostream>
using namespace std;

// Forward declaration of template classes
template <class T>
class Node;

template <class T>
class LSLL;

// Node class
template <class T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node();
    Node(T val);
};

// Linked list class
template <class T>
class LSLL
{
private:
    Node<T>* head;

public:
    LSLL();
    void insertAtHead(T val);
    void insertAtTail(T val);
    void insertBefore(T key, T val);
    void insertAfter(T key, T val);
    void removeAtHead();
    void removeAtTail();
    void remove(T val);
    void removeBefore(T key);
    void removeAfter(T key);
    int search(T key);
    void update(T key, T val);
    int countNodes();
    void display();
    ~LSLL();
    bool removeKthNode(int key, int& val);
    Node<T>* getHead();
    void combine(LSLL& t1, LSLL& t2);
    void reverse();
    void removeDuplicates();
};

#include "LSLL.tpp"

#endif

#ifndef zara_NodeBinaryTree
#define zara_NodeBinaryTree

#include <iostream>
#include "Queue.h"
#include <string>

using namespace std;

template <typename t>
class Node
{
public:
    t info;
    Node<t> *left;
    Node<t> *right;

    Node(t v)
    {
        info = v;
        left = nullptr;
        right = nullptr;
    }
    Node()
    {
        left = nullptr;
        right = nullptr;
    }
};

template <typename t>
class binaryTree
{
private:
    Node<t> *root;

    int height(Node<t>* curr)
    {
      return 1+max(height(curr->left),height(curr->right));
    }

    void getMirrorImage(Node<t>* n)     //Mirror
    {
    if (n==nullptr)
    {
        return ;
    }
    swap(n->left,n->right);
    getMirrorImage(n->left);
    getMirrorImage(n->right);
    }

public:
    binaryTree()
    {
        root = nullptr;
    }
    

    Node<t>* search(Node<t> *curr, t val)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }
        if (curr->info == val)
        {
            return curr;
        }
        Node<t> *temp;
        temp = search(curr->left, val);
        if (temp == nullptr)
        {
            temp = search(curr->right, val);
        }
        return temp;
    }

    Node<t>* searchParent(Node<t> *curr, t val)
    {
        if (curr == nullptr)
            return nullptr;
        if ((curr->left && curr->left->info == val) ||
            (curr->right && curr->right->info == val))
            return curr;
        Node<t> *temp = searchParent(curr->left, val);
        if (temp != nullptr)
            return temp;
        return searchParent(curr->right, val);
    }

    void preorder(Node<t> *curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        cout << curr->info<<" ";
        preorder(curr->left);
        preorder(curr->right);
        return;
    }

    void postorder(Node<t> *curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->info;
        return;
    }

    void inorder(Node<t> *curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        inorder(curr->left);
        cout << curr->info;
        inorder(curr->right);
        return;
    }

    void levelorder(Node<t> *curr)
    {
        if (!curr) return;
        Queue<Node<t> *> q;
        q.enqueue(root);
        while (!q.isEmpty())
        {
            Node<t> *temp = q.dequeue();
            cout << temp->info;
            if (temp->left)
            {
                q.enqueue(temp->left);
            }
            if (temp->right)
            {
                q.enqueue(temp->right);
            }
        }
        return;
    }

    void remove(Node<t> *curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        remove(curr->left);
        remove(curr->right);
        delete curr;
    }

public:
    void setRoot(t val);
    void setLeft(t parent, t val);
    void setRight(t parent, t val);
    t getRoot();
    t getLeft(t parent);
    t getRight(t parent);
    void preOrder();
    void postOrder();
    void inOrder();
    void levelOrder();
    void Remove(t val);
    int countNodes(t k);
    t getParent(t node);
    t findNodeSibling(t node);
    bool isExternalNode( t node ); 
    bool isInternalNode(t node);
    void displayDescendents(t node); 
    void displayParenthesizedView(Node<t>* curr);
    void displayParenthesizedView();
    void heightOfTree();
    void getMirrorImage();
    ~binaryTree();
    binaryTree(binaryTree<t>&);
    void copy(Node<t>* n);
};

template <typename t>
binaryTree<t>::binaryTree(binaryTree<t>& other)
{
    if (this!=other)
    {
        root=other.root;
        root->left=copy(other.root->left);
        root->right=copy(other.root->right);
    }
    
}

template <typename t>
void binaryTree<t>::copy(Node<t>* n){}

template <typename t>
void binaryTree<t>::getMirrorImage()
{
    getMirrorImage(root);
}

template <typename t>
void binaryTree<t>::heightOfTree()   //Height of Tree
{
    int h=height(this->root);
    cout<<h;
}

template <typename t>
void binaryTree<t>::displayParenthesizedView(Node<t>* curr)   //View
{
    if (curr == nullptr)
        return;

    cout << curr->info;
    if (curr->left != nullptr || curr->right != nullptr)
    {
        cout << "(";
        displayParenthesizedView(curr->left);
        cout << ",";
        displayParenthesizedView(curr->right);
        cout << ")";
    }
}

template <typename t> 
void binaryTree<t>::displayParenthesizedView()
{
    displayParenthesizedView(this->root);
}

template <typename t> 
void binaryTree<t>::displayDescendents(t node)   //Descendent
{
    Node<t>* n=search(this->root,node);
    preorder(n->left);
    preorder(n->right);
    return;
} 

template <typename t>              //Internal node
bool binaryTree<t>::isInternalNode(t node)
{
    Node<t>* n=search(this->root,node);
    if(n)
    {
        if(n->left || n->right)
        return true;
        else 
        return false;
    }
    else return false;
    
}

template <typename t>
bool binaryTree<t>::isExternalNode( t node )    //external node?
{
    Node<t>* n=search(this->root, node);
   if(n)
   {
    if(n->left || n->right)
    return false;
    else
    return true;
   }
   else return false;
}

template <typename t>
t binaryTree<t>::findNodeSibling(t node)    //Node sibling
{
    Node<t>* n=searchParent(this->root, node);
    if(n==NULL) return 0;
    if(n->left && n->left->info==node)
    {
        if(n->right) return n->right->info;
    }
    if(n->right && n->right->info==node)
    {
        if(n->left) return n->left->info;
    }
    else 
    {
        return 0;
    }
}

template <typename t>
t binaryTree<t>::getParent(t node)    //Get parent
{
    Node<t>* n=searchParent( this->root, node);
    return n->info;
}

template <typename t>
int binaryTree<t>::countNodes(t k)
{
    if (root==NULL)
    {
        return 0;
    }
    int count=0;

    Queue<Node<t>*> q;

    q.enqueue(root);
    while (!q.is_Empty())
    {
        Node<t>* curr=q.front();
        q.dequeue();
        if (curr->info>k)
        {
            count++;
        }
        if (curr->left)
        {
            q.enqueue(curr->left);
        }
        if (curr->right)
        {
            q.enqueue(curr->right);
        } 
    }
    return count;    
}

template <typename t>
void binaryTree<t>::setRoot(t val)
{
    if (!root)
    {
        root = new Node<t>(val);
    }
    else
    {
        root->info = val;
    }
}

template <typename t>
void binaryTree<t>::setLeft(t parent, t val)
{
    Node<t> *n = search(root, parent);
    if (n && n->left == nullptr)
    {
        n->left = new Node<t>(val);
    }
}

template <typename t>
void binaryTree<t>::setRight(t parent, t val)
{
    Node<t> *n = search(root, parent);
    if (n && n->right == nullptr)
    {
        n->right = new Node<t>(val);
    }
}

template <typename t>
t binaryTree<t>::getRoot()
{
    if (root == nullptr)
    {
        throw "No root exist (getRoot)";
    }
    else
    {
        return root->info;
    }
}

template <typename t>
t binaryTree<t>::getLeft(t parent)
{
    Node<t> *n = search(root, parent);
    if (n == nullptr || n->left == nullptr)
    {
        throw "No left child exist (getLeft)";
    }
    else
    {
        return n->left->info;
    }
}

template <typename t>
t binaryTree<t>::getRight(t parent)
{
    Node<t> *n = search(root, parent);
    if (n == nullptr || n->right == nullptr)
    {
        throw "no right child exist (getRight)";
    }
    else
    {
        return n->right->info;
    }
}

template <typename t>
void binaryTree<t>::preOrder()
{
    preorder(root);
}

template <typename t>
void binaryTree<t>::postOrder()
{
    postorder(root);
}

template <typename t>
void binaryTree<t>::inOrder()
{
    inorder(root);
}

template <typename t>
void binaryTree<t>::levelOrder()
{
    levelorder(root);
}

template <typename t>
void binaryTree<t>::Remove(t val)
{
    Node<t> *parent = searchParent(root, val);
    if (parent != nullptr)
    {
        if (parent->left && parent->left->info == val)
        {
            remove(parent->left);
            parent->left = nullptr;
        } 
        else if (parent->right && parent->right->info == val)
        {
            remove(parent->right);
            parent->right = nullptr;
        }
    }
}

template <typename t>
binaryTree<t>::~binaryTree()
{
    remove(root);
    root=nullptr;
}

#endif
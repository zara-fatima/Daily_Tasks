#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};
template<class T>
class BST
{
private:
	Node<T> *root;
    void inOrderHelper(Node<T> *p);
    void preOrderHelper(Node<T> *p);
    void postOrderHelper(Node<T> *p);
    Node<T>* findMin(Node<T>* node); // Helper function to find the minimum node in a subtree
    Node<T>* deleteNode(Node<T>* root, T node);  // Helper function to delete a node
public:
    int countInternalNodes(Node<T>* p);
    int internalNodes();
    int helpCountLeafNodes(Node<T>* p);
    int countLeafNodes();
    int countNodes();
    int countNodes(Node<T>* p);
	BST() : root(nullptr) {}
	void insert(T node);
	bool search(T node);
	void inOrder();
    void preOrder();
    void postOrder();
	void deleteMethod(T p);
    int helperheight(Node<T>* p);
    int height();
    bool recSearch(T key);
    bool recSearch(Node<T>* n,T key);
    void helperPath(Node<T> *p);
    void printPath();
};

//SEARCH
template<class T>       
bool BST<T>::recSearch(T key)
{
    bool res=recSearch(this->root,key);
    return res;
}

// HELPER SEARCH
template<class T> 
bool BST<T>::recSearch(Node<T>* n,T key)
{
    if(n==nullptr)     return false;
    if(n->data==key)   return true;
    // if(n->data < key)  recSearch(n->left,key);
    // if(n->data > key)  recSearch(n->right,key);
    return  recSearch(n->left,key) + recSearch(n->right,key); ;
}

template<class T>
void BST<T>::helperPath(Node<T> *p) {
    if (p != nullptr) {
        cout << p->data << "-> ";
        helperPath(p->left);
        cout<<endl;
        cout << p->data << "-> ";
        helperPath(p->right);
        
    }
}

// Public function
template<class T>
void BST<T>::printPath() 
{
    helperPath(root);
    cout << endl;
}

template<class T>            //Height of tree
int BST<T>::helperheight(Node<T>* p) 
{
    if (p == nullptr) return -1;  
    return 1 + max(helperheight(p->left), helperheight(p->right));
}

template<class T>             //Helper height
int BST<T>::height()
{
    return helperheight(this->root);
}

template<class T>         //Cont nodes
 int BST<T>::countNodes() { return countNodes(root); } 

template<class T>         //Count nodes helper
int BST<T>::countNodes(Node<T>* p) 
{
    if (p == nullptr) return 0;
    return 1 + countNodes(p->left) + countNodes(p->right);
}

template<class T>          //Insert
void BST<T>::insert(T node) {
    Node<T> *newNode = new Node<T>(node);
    
    if (root == nullptr) {
        root = newNode;
    } else {
        Node<T> *current = root;
        Node<T> *parent = nullptr;
        
        while (current != nullptr) {
            parent = current;
            if (node < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        if (node < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}

// Helper function to find the minimum node in a subtree
template<class T>
Node<T>* BST<T>::findMin(Node<T>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Helper function to delete a node
template<class T>
Node<T>* BST<T>::deleteNode(Node<T>* root, T node) {
    if (root == nullptr) {
        return root;
    }

    if (node < root->data) {
        root->left = deleteNode(root->left, node);
    } else if (node > root->data) {
        root->right = deleteNode(root->right, node);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node<T> *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node<T> *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node<T> *temp = findMin(root->right);
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Public function
template<class T>
void BST<T>::deleteMethod(T node) {
    root = deleteNode(root, node);
}
template<class T>
bool BST<T>::search(T node) {
    Node<T> *current = root;
    while (current != nullptr) {
        if (current->data == node) {
            return true;
        } else if (node < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}
template<class T>
void BST<T>::inOrderHelper(Node<T> *p) {
    if (p != nullptr) {
        inOrderHelper(p->left);
        cout << p->data << " ";
        inOrderHelper(p->right);
    }
}

// Public function
template<class T>
void BST<T>::inOrder() {
    inOrderHelper(root);
    cout << endl;
}
template<class T>
void BST<T>::preOrderHelper(Node<T> *p) {
    if (p != nullptr) {
        cout << p->data << " ";
        preOrderHelper(p->left);
        preOrderHelper(p->right);
    }
}

// Public function
template<class T>
void BST<T>::preOrder() {
    preOrderHelper(root);
    cout << std::endl;
}
template<class T>
void BST<T>::postOrderHelper(Node<T> *p) {
    if (p != nullptr) {
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        cout << p->data << " ";
    }
}

// Public function
template<class T>
void BST<T>::postOrder() {
    postOrderHelper(root);
    cout << endl;
}

// template<class T>
// int BST<T>::internalNodes()
// {
//     return countInternalNodes(this->root);
// }

// template<class T>
// int BST<T>::countInternalNodes(Node<T>* p) {
//     if (p == nullptr) return 0;

//     // leaf → not internal
//     if (p->left == nullptr && p->right == nullptr)
//         return 0;

//     // internal node → count it and continue
//     return 1 + countInternalNodes(p->left) + countInternalNodes(p->right);
// }

// template<class T>        //Helper of Count leaf nodes
// int BST<T>::helpCountLeafNodes(Node<T>* p) 
// {
//     if (p == nullptr) return 0;
//     if (p->left == nullptr && p->right == nullptr) return 1;
//     return helpCountLeafNodes(p->left) + helpCountLeafNodes(p->right);
// }

// template<class T>      //Count leaf nodes
// int BST<T>::countLeafNodes()
// {
//     return helpCountLeafNodes(this->root);
// }

//lEVEL ORDER TRAVERSAL
// void levelOrder() {
//     if(root == nullptr) return;

//     queue<Node<T>*> q;
//     q.push(root);

//     while(!q.empty()) {
//         Node<T>* temp = q.front(); q.pop();
//         cout << temp->data << " ";
//         if(temp->left) q.push(temp->left);
//         if(temp->right) q.push(temp->right);
//     }
// }

// Nodes at a Specific Level
// void printLevel(Node<T>* p, int level) {
//     if (p == nullptr) return;
//     if (level == 0) cout << p->data << " ";
//     else {
//         printLevel(p->left, level-1);
//         printLevel(p->right, level-1);
//     }
// }

// Mirror
// void mirror(Node<T>* p) {
//     if (p == nullptr) return;
//     swap(p->left, p->right);
//     mirror(p->left);
//     mirror(p->right);
// }

// check if bst is valid
// bool isBST(Node<T>* p, T min, T max) {
//     if (p == nullptr) return true;
//     if (p->data <= min || p->data >= max) return false;
//     return isBST(p->left, min, p->data) && isBST(p->right, p->data, max);
// }


// template <class T>
// void BST<T>:: buildFromPreorder(T arr[], int n)
// {
//     root = nullptr; // clear existing tree
//     for (int i = 0; i < n; i++)
//         insert(arr[i]);     // use your insert() function
// }



#include <iostream>
using namespace std;
class StudentNode
{
public:
    int rollNo;
    string name;
    double cgpa;
    StudentNode* left;
    StudentNode* right;
    StudentNode(int value,string _name, double _cgpa) : rollNo(value), name(_name), cgpa(_cgpa), left(nullptr), right(nullptr) {}
};

class StudentBST
{
    private:
    StudentNode* root;

    public:

    StudentBST()
    {
        this->root=nullptr;
    }

    bool insert(int rollno, string nm, double _cgpa)      //INSERT
    {
        if (root == nullptr) 
        {
          StudentNode* newNode=new StudentNode(rollno, nm, _cgpa);
          root = newNode;
          return true;
        }
        else 
        {
        StudentNode* current = root;
        StudentNode* parent = nullptr;
        
        while (current != nullptr) 
        {
            parent = current;
            if(current->rollNo==rollno) return false;
            if (rollno < current->rollNo) 
            {
                current = current->left;
            } 
            else 
            {
                current = current->right;
            }
        }
        StudentNode* newNode=new StudentNode(rollno, nm, _cgpa);
        if (rollno < parent->rollNo) 
        {
            parent->left = newNode;
            return true;
        } 
        else 
        {
            parent->right = newNode;
            return true;
        }
        }
    } 

    bool search(int rollno)      //SEARCH
    {
    StudentNode *current = root;
    while (current != nullptr) {
        if (current->rollNo == rollno) 
        {
            cout<<"Roll no: "<<current->rollNo<<endl
            <<"Name: "<<current->name<<endl
            <<"CGPA: "<<current->cgpa<<endl;
            return true;
        } 
        else if (rollno < current->rollNo) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    return false;
}

void inOrderHelper(StudentNode* p) 
{
    if (p != nullptr) 
    {
        inOrderHelper(p->left);
        cout << p->rollNo <<"\t        "<<p->name<<"\t "<<p->cgpa<<endl;
        inOrderHelper(p->right);
    }
}

// Public function
void inOrder() 
{
    cout<<"Roll no: \tName: \tCGPA:\t"<<endl;
    inOrderHelper(this->root);
    cout << endl;
}

~StudentBST()
{
    destroy(this->root);
}

void destroy(StudentNode* s)
{
    if(!s) return;
    destroy(s->left);
    destroy(s->right);
    delete s;
}

StudentNode* findMin(StudentNode* node) {
    while (node->left != nullptr) 
    {
        node = node->left;
    }
    return node;
}

StudentNode* deleteNode(StudentNode* root ,int rn) 
{
    if (root == nullptr) 
    {
        return root;
    }

    if (rn < root->rollNo) 
    {
        root->left = deleteNode(root->left, rn);
    } 
    else if (rn > root->rollNo) 
    {
        root->right = deleteNode(root->right, rn);
    } 
    else 
    {
        // Node with only one child or no child
        if (root->left == nullptr) 
        {
            StudentNode *temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == nullptr) 
        {
            StudentNode *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        StudentNode *temp = findMin(root->right);
        root->rollNo = temp->rollNo;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->rollNo);
    }
    return root;
}

// Public function
void deleteMethod(int node) 
{
    root = deleteNode(root, node);
}

void inRangeHelper(StudentNode* p, double start , double end) 
{
    if (p != nullptr) 
    {
        inRangeHelper(p->left,start,end);
        if(p->cgpa >= start && p->cgpa <= end)
        {
            cout << p->rollNo <<"\t        "<<p->name<<"\t "<<p->cgpa<<endl;
        }
        inRangeHelper(p->right,start,end);
    }
}

// Public function
void inRange(double start, double end) 
{
    cout<<"Roll no: \tName: \tCGPA:\t"<<endl;
    inRangeHelper(this->root,start,end);
    cout << endl;
}

};

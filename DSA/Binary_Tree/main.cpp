#include<iostream>
#include"NodeBinaryTree.h"
using namespace std;
int main()
{
    binaryTree<int> bt;
    bt.setRoot(1);
    bt.setLeft(1,2);
    bt.setRight(1,3);
    bt.setLeft(2,4);
    bt.setRight(2,5);
    bt.setLeft(3,6);
    bt.setRight(3,7);
    cout<<"TREE"<<endl;
    bt.levelOrder();
    cout<<endl<<"Get parent: ";
    int info=bt.getParent(4);
    cout<<info;

// Node sibling

    int sibling=bt.findNodeSibling(6);
    if(sibling==0)
    cout<<endl<<"Does not have a sibling."<<endl;
    else
    cout<<endl<<"Node sibling: "<<sibling<<endl;

 // External node

    bool res=bt.isExternalNode(2);
    if (res==true)
    {
        cout<<"It is an external node.";
    }
    else
    {
        cout<<"It is not an external node.";
    }
    cout<<endl;

// Internal node

    bool res1=bt.isInternalNode(1);
    if (res1==true)
    {
        cout<<"It is an internal node.";
    }
    else
    {
        cout<<"It is not an internal node.";
    }

// Descendents

cout<<endl;
cout<<"Descendents: ";
bt.displayDescendents(2);
cout<<endl;

// Parenthesized view

cout<<"Parenthesized view: ";
bt.displayParenthesizedView();

// // // Height of tree
// cout<<endl<<"Height of tree: ";
// bt.heightOfTree();

// Mirror 

cout<<endl<<"Mirror Image: "<<endl;
bt.getMirrorImage();
bt.levelOrder();
    return 0;
    
}
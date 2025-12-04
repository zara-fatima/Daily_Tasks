#include<iostream>
#include"BST.h"
int main()
{
	BST<int> obj;
	obj.insert(5);
	obj.insert(3);
	obj.insert(7);	
	obj.insert(2);
	obj.insert(4);
	obj.insert(6);
	obj.insert(8);

	cout<<endl<<"Inorder: ";
	obj.inOrder();

    int count=obj.countNodes();
    cout<<endl<<"Total nodes: "<<count<<endl;

 	// obj.deleteMethod(2);
	// cout<<endl<<"After deleting:";
 	// obj.inOrder();

	int h=obj.height();
	cout<<endl<<"Height: "<<h<<endl;

	bool out=obj.recSearch(6);
	cout<<"Result: "<<out;

	cout<<endl;
	obj.printPath();
	return 0;
}
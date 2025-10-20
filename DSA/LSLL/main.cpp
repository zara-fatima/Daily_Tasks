#include "LSLL.h"

int main()
{
    LSLL<int> list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAfter(20, 25);
    list.insertBefore(10, 5);

    cout << "\nList after insertions:\n";
    list.display();

    list.remove(25);
    list.removeAtHead();
    list.removeAtTail();

    cout << "\nAfter deletions:\n";
    list.display();

    list.insertAtTail(40);
    list.insertBefore(40, 35);
    list.insertAfter(99, 70);

    cout << "\nAfter more insertions:\n";
    list.display();

    list.update(20, 99);
    cout << "\nAfter update:\n";
    list.display();

    list.removeBefore(99);
    list.removeAfter(99);

    cout << "\nAfter before/after deletions:\n";
    list.display();

    if (list.search(99))
        cout << "\nElement 99 found!\n";
    else
        cout << "\nElement 99 not found!\n";

    cout << "Total Nodes: " << list.countNodes() << endl;

    return 0;
}

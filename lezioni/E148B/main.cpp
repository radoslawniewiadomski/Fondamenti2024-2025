#include <iostream>
#include "Node.h"
#include "List.h"

using namespace std;

int main() {
    List l;

    l.insertFront(10);

    l.insertFront(20);

    l.print();  cout << endl;

    l.insertBack(120);

    l.print(); cout << endl;

    l.insertAfter(l.find(20), 500);

    l.print(); cout << endl;

    return 0;
}

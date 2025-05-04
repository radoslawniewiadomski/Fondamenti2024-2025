#include "Node.h"

class List
{
    Node* _head;
    int _numItems;

public:
    List();
    ~List();

    Node* getHead() const;
    int getNumItems() const;

    void insertFront(int data);
    void insertBack(int data);
    void insertAfter(Node* p, int data);

    void clear();
    Node* find(int data) const;
    bool isEmpty() const;
    void print() const;
};

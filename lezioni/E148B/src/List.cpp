#include <iostream>
#include "List.h"

using namespace std;

void List::print() const
{
    Node* p = _head;

    while (p != 0)
    {
        cout<< p->getData() << ", ";
        p = p->getNext();
    }
}


Node* List::find(int data) const
{
    Node* p = _head;
    while (p != 0)
    {
        if (p->getData() == data)
            return p;

        p = p->getNext();
    }
    return 0;
}

void List::insertAfter(Node* p, int data)
{
    if (p != 0)
    {
        Node* pNew = new Node(data, p->getNext());

    p->setNext(pNew);

        _numItems++;
    }
}

void List::insertBack(int data)
{
    if (_head != 0)
    {

        Node* pNew = new Node(data, 0);
        Node* p = _head;


        while (p->getNext() != 0) p = p->getNext();


	  p->setNext(pNew);
        _numItems++;

    }
    else
        insertFront(data);
}
void List::insertFront(int data)
{
    Node* pNew = new Node(data, _head);

    _head = pNew;
    _numItems++;
}

Node* List::getHead() const
{
    return _head;
}

bool List::isEmpty() const
{
    return (_head == 0);
}

int List::getNumItems() const
{
    return _numItems;
}

List::List()
    : _head(0), _numItems(0) {}


List::~List()
{
    clear();
}

void List::clear()
{
    Node* p = _head;

    while (p != 0)
    {
        Node* q = p;
        p = p->getNext();
        delete q;
    }

    _head = 0;
    _numItems = 0;
}


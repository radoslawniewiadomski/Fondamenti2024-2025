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

void List::removeFront()
{
    if (_head != 0)
    {
        Node* temp = _head;
        _head = _head->getNext();

        delete temp;
        _numItems--;
    }
}

void List::removeBack()
{
    if (_head != 0)
    {
        if (_head->getNext() != 0)
        {
            Node* p = _head->getNext();
            Node* q = _head;
            while (p->getNext() != 0)
            {
                q = q->getNext();
                p = p->getNext();
            }
            q->setNext(0);
            delete p;
        }
        else
        {
            delete _head;
            _head = 0;
        }
        _numItems--;
    }
}

void List::removeAt(Node* p)
{
    if (_head != 0)
    {
        Node* q = _head;
        if (q == p) removeFront();
        else
        {
            while (q->getNext() != 0 && q->getNext() != p)
                q = q->getNext();

            if (q->getNext() != 0)
            {
                q->setNext(p->getNext());
                delete p;
                _numItems--;
            }
        }
    }
}


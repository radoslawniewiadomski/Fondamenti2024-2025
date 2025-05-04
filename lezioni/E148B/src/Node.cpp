#include "Node.h"

Node::Node() : _data(0), _next(0) {}

Node::Node(int data, Node* next): _data(data), _next(next) {}

Node::Node(const Node& node): _data(node._data), _next(node._next) { }

Node::~Node() {}

int Node::getData() const
{
    return _data;
}

Node* Node::getNext() const
{
    return _next;
}

void Node::setData(int data)
{
    _data = data;
}

void Node::setNext(Node* next)
{
    _next = next;
}

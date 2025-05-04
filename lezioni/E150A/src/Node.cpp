#include "Node.h"

template <typename T>
Node<T>::Node(): _data(0), _next(0) {}

template <typename T>
Node<T>::Node(const T& data, Node<T>* next): _data(data), _next(next) {}

template <typename T>
Node<T>::Node(const Node<T>& node): _data(node._data), _next(node._next) {}

template <typename T>
Node<T>::~Node() {}

template <typename T>
const T& Node<T>::getData() const
{
    return _data;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
    return _next;
}

template <typename T>
void Node<T>::setData(const T& data)
{
    _data = data;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
    _next = next;
}




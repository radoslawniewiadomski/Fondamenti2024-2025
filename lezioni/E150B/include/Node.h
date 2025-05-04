#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
    T _data;
    Node<T>* _next;

public:
    // costruttori e distruttore
    Node();
    Node(const T& data, Node<T>* next);
    Node(const Node<T>& node);
    ~Node();

    // selettori
    const T& getData() const;
    Node<T>* getNext() const;

    // modificatori
    void setData(const T& data);
    void setNext(Node<T>* next);
};

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


#endif // NODE_H

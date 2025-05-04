#ifndef NODE_H
#define NODE_H


class Node {
    int _data;
    Node* _next;

public:
    // costruttori e distruttore
    Node(int data, Node* next);
    Node(const Node& node);
    Node();
    ~Node();

    // selettori e modificatori
    int getData() const;
    Node* getNext() const;
    void setData(int data);
    void setNext(Node* next);
};


#endif // NODE_H

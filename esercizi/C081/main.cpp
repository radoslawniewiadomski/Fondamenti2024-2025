#include <iostream>
#include <cstring>

using namespace std;

class film
{
    char* _titolo;
    int _durata;
    int _anno;

public:
    // Costruttori
    film();
    film(char* titolo, int durata, int anno);
    // Costruttore di copia
    film(const film& otherFilm);
    // Distruttore
    ~film();

    // Selettori e modificatori
    char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);

    void stampaFilm();

    bool operator==(const film& film1) const;

    friend ostream& operator<<(ostream& os, const film& film);
    friend istream& operator>>(istream& is, film& film);
};

film::film()
{
    _titolo = new char[20];
    strcpy(_titolo, "N/D");
    _durata = 0;
    _anno = 0;
}

film::film(char* titolo, int durata, int anno)
{
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
    _durata = durata;
    _anno = anno;
}

film::film(const film& otherFilm)
{
    _titolo = new char[strlen(otherFilm._titolo) + 1];
    strcpy(_titolo, otherFilm._titolo);
    _durata = otherFilm._durata;
    _anno = otherFilm._anno;
}

film::~film()
{
    delete[] _titolo;
}

char* film::getTitolo() const
{
    return _titolo;
}

void film::setTitolo(const char* titolo)
{
    delete[] _titolo;
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
}

int film::getDurata() const
{
    return _durata;
}

void film::setDurata(int durata)
{
    _durata = durata;
}

int film::getAnno() const
{
    return _anno;
}

void film::setAnno(int anno)
{
    _anno = anno;
}

void film::stampaFilm()
{
    cout << "Titolo: " << _titolo << endl;
    cout << "Durata: " << _durata << " minuti" << endl;
    cout << "Anno: " << _anno << endl;
}

bool film::operator==(const film& film1) const
{
    // Compare titolo, durata, and anno of the two films
    return (strcmp(this->getTitolo(), film1.getTitolo()) == 0 &&
            this->getDurata() == film1.getDurata() &&
            this->getAnno() == film1.getAnno());
}





template <typename T>
class Node
{
public:
    Node(const T& data, Node<T>* next);
    Node(const Node<T>& node);
    ~Node();
    // selettori
    const T& getData() const;
    Node<T>* getNext() const;
    // modificatori
    void setData(const T& data);
    void setNext(Node<T>* next);

private:
    Node();
    T _data;
    Node<T>* _next;
};


template <typename T>
Node<T>::Node() : _data(), _next(0) {}

template <typename T>
Node<T>::Node(const T& data, Node<T>* next)
    : _data(data), _next(next) {}

template <typename T>
Node<T>::Node(const Node<T>& node)
    : _data(node._data), _next(node._next) {}

template <typename T>
Node<T>::~Node() {}

template <typename T>
inline const T& Node<T>::getData() const
{
    return _data;
}
template <typename T>
inline Node<T>* Node<T>::getNext() const
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

////////////////////////////////////////////////////////////////////////////

template <typename T>
class Stack
{
    Node<T>* _head;
    int _numItems;

public:
    // costruttori e distruttore
    Stack();
    Stack(const Stack<T>& s);
    ~Stack();
    // selettori per gli attributi
    int isEmpty() const;
    int numItems() const;
    // operazioni
    void push(const T& data);
    void pop();
    Node<T>* getHead() const;
    void clear();
};


template <typename T>
Stack<T>::Stack() : _head(NULL), _numItems(0) {}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) : _head(nullptr), _numItems(0)
{
    Node<T>* temp = s._head;
    while (temp != nullptr)
    {
        push(temp->data);
        temp = temp->next;
    }
}

template <typename T>
Stack<T>::~Stack()
{
    clear();
}

template <typename T>
int Stack<T>::isEmpty() const
{
    return _head == nullptr;
}

template <typename T>
int Stack<T>::numItems() const
{
    return _numItems;
}

template <typename T>
void Stack<T>::push(const T& data)
{
    Node<T>* newNode = new Node<T>(data, _head);
    _head = newNode;
    _numItems++;
}

template <typename T>
void Stack<T>::pop()
{
    if (_head != nullptr)
    {
        Node<T>* temp = _head;
        _head = _head->getNext();
        delete temp;
        _numItems--;
    }
}

template <typename T>
Node<T>* Stack<T>::getHead() const
{
    return _head;
}

template <typename T>
void Stack<T>::clear()
{
    while (!isEmpty())
        pop();
}


ostream& operator<<(ostream& os, const film& film)
{
    os << "Titolo: " << film._titolo << ", Durata: " << film._durata << " minuti, Anno: " << film._anno;
    return os;
}

istream& operator>>(istream& is, film& film)
{
    char temp[100];
    is >> temp;
    film._titolo = new char[strlen(temp) + 1];
    strcpy(film._titolo, temp);
    is >> film._durata >> film._anno;
    return is;
}

int main()
{
    Stack<film> pila;
    pila.push(film("Matrix", 120, 1999));
    pila.push(film("Pirates", 120, 2005));
    pila.push(film("Oppenheimer", 140, 1999));

    if (!pila.isEmpty())
    {
        film f1 = pila.getHead()->getData();
        cout << f1 << endl;
    }
    else cout <<"Non ci sono i film"<<endl;

    pila.pop();

    if (!pila.isEmpty())
    {
        film f1 = pila.getHead()->getData();
        cout << f1 << endl;
    }
    else cout <<"Non ci sono i film"<<endl;

    pila.pop();

    if (!pila.isEmpty())
    {
        film f1 = pila.getHead()->getData();
        cout << f1 << endl;
    }
    else cout <<"Non ci sono i film"<<endl;

    pila.clear();

    if (!pila.isEmpty())
    {
        film f1 = pila.getHead()->getData();
        cout << f1 << endl;
    }
    else cout <<"Non ci sono i film"<<endl;

    return 0;
}

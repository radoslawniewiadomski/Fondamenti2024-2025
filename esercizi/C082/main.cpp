#include <iostream>
#include <cstring>

using namespace std;

class Person
{
    char _nome[32];
    char _cognome[32];
public:
    Person(const char* nome, const char* cognome);
    Person();
    void stampa() const;
};

Person::Person()
{
    strcpy(_nome, "N/D");
    strcpy(_cognome, "N/D");
}

Person::Person(const char* nome, const char* cognome)
{
    strcpy(_nome, nome);
    strcpy(_cognome, cognome);
}

void Person::stampa() const
{
    cout << "Nome: " << _nome << ", Cognome: " << _cognome << endl;
}

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node(const T& newData) : data(newData), next(nullptr) {}
};

/////////////////////////////////////////////////////////////////////////

template <typename T>
class Queue
{
    Node<T>* _head;
    Node<T>* _tail;
    int _numItems;

public:
    Queue() : _head(nullptr), _tail(nullptr), _numItems(0) {}

    Queue(const Queue<T>& q) : _head(nullptr), _tail(nullptr), _numItems(0)
    {
        Node<T>* temp = q._head;
        while (temp != nullptr)
        {
            insert(temp->data);
            temp = temp->next;
        }
    }

    ~Queue()
    {
        clear();
    }

    int isEmpty() const
    {
        return _head == nullptr;
    }

    int numItems() const
    {
        return _numItems;
    }

    void insert(const T& data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty())
        {
            _head = _tail = newNode;
        }
        else
        {
            _tail->next = newNode;
            _tail = newNode;
        }
        _numItems++;
    }

    void remove()
    {
        if (!isEmpty())
        {
            Node<T>* temp = _head;
            _head = _head->next;
            delete temp;
            _numItems--;
        }
    }

    Node<T>* getHead() const
    {
        return _head;
    }

    void clear()
    {
        while (!isEmpty())
        {
            remove();
        }
    }
};

/////////////////////////////////////////////////////////////////////////


int main()
{
    Queue<Person> coda;
    int scelta;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Inserire dati di nuova persona" << endl;
        cout << "2. Visualizzare dati della prima persona inserita e rimuoverla dalla coda" << endl;
        cout << "0. Uscire" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta)
        {
        case 1:
        {
            char nome[32], cognome[32];
            cout << "Inserisci il nome: ";
            cin >> nome;
            cout << "Inserisci il cognome: ";
            cin >> cognome;
            coda.insert(Person(nome, cognome));
            break;
        }
        case 2:
        {
            if (!coda.isEmpty())
            {
                Person primaPersona = coda.getHead()->data;
                primaPersona.stampa();
                coda.remove();
            }
            else
            {
                cout << "La coda è vuota." << endl;
            }
            break;
        }
        case 0:
            cout << "Programma terminato." << endl;
            break;
        default:
            cout << "Scelta non valida." << endl;
        }
    }
    while (scelta != 0);

    return 0;
}

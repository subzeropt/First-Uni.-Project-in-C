#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template <class T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeLast() {
        if (!tail) return;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    // Exemplo de uma pilha
    void insertEnd(T val)
    {
        Node<T>* ne2wNode = new Node<T>(val);
        tail->next = mewNode;
        newNode->prev = tail;
        tail=newNode;
    }


    //Insere em aqualquer posiçao
    void insertAt(int pos, T val) {
        Node<T>* newNode = new Node<T>(val);
        if(pos<=0)
           return;

        if (pos == 0 || !head) {
            // Inserir no início
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
            return;
        }

        Node<T>* current = head;
        int index = 0;

        while (current->next && index < pos - 1) {
            current = current->next;
            index++;
        }

        if (!current->next) {
            // Inserir no fim
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
        } else {
            // Inserir no meio
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;// no campo prev do ultimo elemento coloca o endereço do novo elemento
            current->next = newNode;
        }
    }

    void display() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList<int> list;

    list.append(10);
    list.append(30);
    list.append(40);

    cout << "Original: ";
    list.display();

    list.insertAt(1, 20); // Inserir 20 na posição 1
    cout << "Após inserir 20 na posição 1: ";
    list.display();

    list.insertAt(0, 5); // Inserir no início
    list.insertAt(10, 50); // Inserir no fim
    cout << "Lista final: ";
    list.display();

    return 0;
}

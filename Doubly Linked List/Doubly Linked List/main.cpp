#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (!tail) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = NULL;
        }
        else {
            head = NULL;
        }
        delete temp;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->prev = head;
            head->next = head;
        }
        else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->prev = head;
            head->next = head;
        }
        else {
            newNode->prev = head->prev;
            newNode->next = head;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node* temp = head;
        if (head == head->next) {
            head = NULL;
        }
        else {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node* temp = head->prev;
        if (head == temp) {
            head = NULL;
        }
        else {
            temp->prev->next = head;
            head->prev = temp->prev;
        }
        delete temp;
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    // Doubly Linked List operations
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    cout << "Doubly Linked List: ";
    dll.display();
    dll.deleteAtBeginning();
    dll.deleteAtEnd();
    cout << "Doubly Linked List after deletion: ";
    dll.display();

    // Circular Linked List operations
    cll.insertAtBeginning(5);
    cll.insertAtEnd(15);
    cll.insertAtEnd(25);
    cout << "Circular Linked List: ";
    cll.display();
    cll.deleteAtBeginning();
    cll.deleteAtEnd();
    cout << "Circular Linked List after deletion: ";
    cll.display();

    return 0;
}

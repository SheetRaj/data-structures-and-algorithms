#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
             cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
             cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        Node* prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        delete current;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
             cout << current->data << " ";
            current = current->next;
        }
         cout << "\n";
    }

};

int main() {
    LinkedList list;

    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtBeginning(2);
    list.insertAtEnd(15);

    cout << "Original list: ";
    list.display();

    list.deleteAtBeginning();
    list.deleteAtEnd();

    cout << "List after deletions: ";
    list.display();

    return 0;
}

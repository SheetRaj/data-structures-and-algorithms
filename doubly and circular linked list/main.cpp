#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;
    ListNode(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

ListNode* insertAtHead(int data, ListNode* head) {
    if (head == NULL) {
        ListNode* node = new ListNode(data);
        node->next = node;
        node->prev = node;
        return node;
    }
    ListNode* temp = new ListNode(data);
    temp->next = head;
    temp->prev = head->prev;
    head->prev->next = temp;
    head->prev = temp;
    return temp;
}

ListNode* insertAtTail(int data, ListNode* head) {
    if (head == NULL) {
        ListNode* node = new ListNode(data);
        node->next = node;
        node->prev = node;
        return node;
    }
    ListNode* temp = new ListNode(data);
    temp->next = head;
    temp->prev = head->prev;
    head->prev->next = temp;
    head->prev = temp;
    return head;
}

ListNode* deleteAtHead(ListNode* head) {
    if (head == NULL) return head;
    if (head->next == head) {
        delete(head);
        return NULL;
    }

    ListNode* temp = head;
    head->next->prev = head->prev;
    head->prev->next = head->next;
    head = head->next;
    delete(temp);

    return head;
}

ListNode* deleteAtTail(ListNode* head) {
    if (head == NULL) return head;
    if (head->next == head) {
        delete(head);
        return NULL;
    }

    ListNode* temp = head->prev;
    head->prev = temp->prev;
    temp->prev->next = head;
    delete(temp);

    return head;
}

void display(ListNode* head) {
    if (head == NULL) return;
    ListNode* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    cout << "Doubly Circular Linked List" << endl;
    ListNode* head = NULL;

    // Insertion at the head
    head = insertAtHead(15, head);
    head = insertAtHead(24, head);
    head = insertAtHead(36, head);

    cout << "After inserting at the head: ";
    display(head);

    // Insertion at the tail
    head = insertAtTail(47, head);
    head = insertAtTail(52, head);
    head = insertAtTail(69, head);

    cout << "After inserting at the tail: ";
    display(head);

    // Deletion at the head and tail
    head = deleteAtHead(head);
    head = deleteAtTail(head);

    cout << "After deleting at the head and tail: ";
    display(head);

    return 0;
}

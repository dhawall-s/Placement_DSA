#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}


void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Position out of range!" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteNode(Node*& head, int val) {
    if (!head) return;
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val)
        temp = temp->next;
    if (!temp->next) return;
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


void deleteList(Node*& head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}

int main() {
    Node* head = NULL;

    
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    cout << "Linked List after insertions: ";
    printList(head);

   
    insertAtHead(head, 5);
    cout << "After inserting at head: ";
    printList(head);

    
    insertAtPosition(head, 25, 3);
    cout << "After inserting 25 at position 3: ";
    printList(head);

    
    deleteNode(head, 30);
    cout << "After deleting 30: ";
    printList(head);

    
    head = reverseList(head);
    cout << "Reversed Linked List: ";
    printList(head);

    
    deleteList(head);
    cout << "Linked List deleted!" << endl;

    return 0;
}

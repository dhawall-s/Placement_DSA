#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseInGroups(Node* head, int k) {
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != nullptr)
        head->next = reverseInGroups(next, k);

    return prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    int k = 2;
    head = reverseInGroups(head, k);
    printList(head);

    return 0;
}

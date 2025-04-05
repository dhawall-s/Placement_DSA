#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* removeDuplicates(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* nextNext = current->next->next;
            delete current->next;
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    std::cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    std::cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

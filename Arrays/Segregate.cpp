#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:
    Node* segregate(Node* head) {
        int count[3] = {0, 0, 0};
        Node* temp = head;

        while (temp != NULL) {
            count[temp->data]++;
            temp = temp->next;
        }

        temp = head;
        int i = 0;
        while (temp != NULL) {
            if (count[i] == 0) {
                ++i;
            } else {
                temp->data = i;
                --count[i];
                temp = temp->next;
            }
        }

        return head;
    }
};

// Helper function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to insert a new node at the end
Node* insert(Node* head, int data) {
    if (!head) return new Node(data);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(data);
    return head;
}

int main() {
    Node* head = nullptr;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 0);
    head = insert(head, 2);
    head = insert(head, 2);

    Solution obj;
    head = obj.segregate(head);

    printList(head);

    return 0;
}

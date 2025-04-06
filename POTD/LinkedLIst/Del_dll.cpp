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
    Node* deleteNode(Node* head, int x) {
        if (head == nullptr) return nullptr;

        if (x == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        Node* curr = head;
        for (int i = 1; curr != nullptr && i < x - 1; i++) {
            curr = curr->next;
        }

        if (curr == nullptr || curr->next == nullptr) return head;

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        return head;
    }
};

Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    Node* head = nullptr;

    int n, x, pos;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        head = insertAtEnd(head, x);
    }

    cout << "Enter position to delete (1-based index): ";
    cin >> pos;

    head = sol.deleteNode(head, pos);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}

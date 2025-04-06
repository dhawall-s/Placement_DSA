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
    bool areIdentical(struct Node* head1, struct Node* head2) {
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data != head2->data)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1 == nullptr && head2 == nullptr;
    }
};

// Helper function to insert at the end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Helper function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    int n1, n2, val;
    cout << "Enter number of nodes in List 1: ";
    cin >> n1;
    cout << "Enter elements of List 1: ";
    for (int i = 0; i < n1; ++i) {
        cin >> val;
        head1 = insertAtEnd(head1, val);
    }

    cout << "Enter number of nodes in List 2: ";
    cin >> n2;
    cout << "Enter elements of List 2: ";
    for (int i = 0; i < n2; ++i) {
        cin >> val;
        head2 = insertAtEnd(head2, val);
    }

    if (sol.areIdentical(head1, head2))
        cout << "The linked lists are identical." << endl;
    else
        cout << "The linked lists are not identical." << endl;

    return 0;
}

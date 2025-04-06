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
    int getKthFromLast(Node *head, int k) {
        Node* fast = head;
        Node* slow = head;
        
        for (int i = 0; i < k; i++) {
            if (fast == nullptr) return -1;
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }
};

// Function to insert node at end
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

// Function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, k, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }
    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;
    int result = obj.getKthFromLast(head, k);
    
    if (result != -1)
        cout << "Kth node from the end is: " << result << endl;
    else
        cout << "Invalid value of k." << endl;

    return 0;
}

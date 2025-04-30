#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, there is a loop
            if (slow == fast) {
                return countLoopLength(slow);
            }
        }

        // No loop found
        return 0;
    }

  private:
    int countLoopLength(Node* nodeInLoop) {
        Node* temp = nodeInLoop;
        int count = 1;
        while (temp->next != nodeInLoop) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

// Helper function to create a loop for testing
void createLoop(Node* head, int c) {
    if (c == 0) return;

    Node* loopNode = head;
    for (int i = 1; i < c; i++) {
        if (loopNode->next)
            loopNode = loopNode->next;
    }

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = loopNode;
}

// Test the function
int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5 with loop at position 2
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int c = 2; // create loop at 2nd node (1-based index)
    createLoop(head, c);

    Solution sol;
    int loopLength = sol.countNodesinLoop(head);
    cout << "Length of loop is: " << loopLength << endl;

    return 0;
}

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle of the linked list
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        Node* secondHalfStart = reverseList(slow->next);

        // Step 3: Compare the first and second halves
        Node* firstHalfStart = head;
        Node* secondHalfCopy = secondHalfStart;
        bool isPalin = true;
        while (secondHalfStart) {
            if (firstHalfStart->data != secondHalfStart->data) {
                isPalin = false;
                break;
            }
            firstHalfStart = firstHalfStart->next;
            secondHalfStart = secondHalfStart->next;
        }

        // Step 4: Restore the original list (optional)
        slow->next = reverseList(secondHalfCopy);

        return isPalin;
    }

private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

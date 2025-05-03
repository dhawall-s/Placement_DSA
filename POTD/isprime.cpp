
#include <iostream>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int nearestPrime(int num) {
        if (isPrime(num)) return num;

        int lower = num - 1;
        int upper = num + 1;

        while (true) {
            if (lower >= 2 && isPrime(lower)) return lower;
            if (isPrime(upper)) return upper;
            lower--;
            upper++;
        }
    }

    Node* primeList(Node* head) {
        Node* curr = head;
        while (curr != nullptr) {
            curr->val = nearestPrime(curr->val);
            curr = curr->next;
        }
        return head;
    }
};

// Utility function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from an array
Node* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new Node(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> values = {1, 15, 20};  // Change input here
    Node* head = createList(values);

    Solution sol;
    head = sol.primeList(head);

    printList(head);  // Output: 2 -> 13 -> 19
    return 0;
}

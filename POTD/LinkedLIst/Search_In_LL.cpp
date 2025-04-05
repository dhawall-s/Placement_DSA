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

class Solution {
public:
    bool searchKey(int n, Node* head, int key) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == key)
                return true;
            current = current->next;
        }
        return false;
    }
};

Node* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

int main() {
    Solution ob;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3; 

    Node* head = createLinkedList(arr, n);
    
    cout << (ob.searchKey(n, head, key) ? "true" : "false") << endl;

    return 0;
}

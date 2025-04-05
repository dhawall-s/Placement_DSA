#include <iostream>
#include <vector>
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
    Node* constructLL(vector<int>& arr) {
        if (arr.empty()) return NULL; 

        Node* head = new Node(arr[0]);
        Node* tail = head;

        for (int i = 1; i < arr.size(); i++) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        return head;
    }
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution ob;
    vector<int> arr = {1, 2, 3, 4, 5}; 

    Node* ans = ob.constructLL(arr); 
    printList(ans);

    return 0;
}

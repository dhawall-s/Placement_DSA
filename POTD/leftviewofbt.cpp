#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to build a tree from level order input
Node* buildTree(const string& str) {
    if (str.length() == 0 || str[0] == 'N') return nullptr;

    vector<string> ip;
    istringstream iss(str);
    for (string val; iss >> val; ) ip.push_back(val);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < ip.size()) {
        Node* currNode = q.front();
        q.pop();

        // Left child
        if (ip[i] != "N") {
            currNode->left = new Node(stoi(ip[i]));
            q.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;

        // Right child
        if (ip[i] != "N") {
            currNode->right = new Node(stoi(ip[i]));
            q.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

class Solution {
public:
    vector<int> leftView(Node *root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();

                if (i == 0) result.push_back(node->data); // Leftmost node of this level

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};

// Main function to test the code
int main() {
    string input;
    cout << "Enter tree in level-order (use N for nulls): ";
    getline(cin, input);

    Node* root = buildTree(input);

    Solution sol;
    vector<int> leftViewResult = sol.leftView(root);

    cout << "Left View: ";
    for (int val : leftViewResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

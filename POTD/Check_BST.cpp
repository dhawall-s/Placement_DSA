#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    void inorder(Node* root, vector<int>& temp) {
        if (!root) return;
        inorder(root->left, temp);
        temp.push_back(root->data);
        inorder(root->right, temp);
    }

    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        if (!root) return true;
        vector<int> temp;
        inorder(root, temp);
        for (size_t i = 0; i < temp.size() - 1; i++) {
            if (temp[i] > temp[i + 1]) 
                return false;
        }
        return true;
    }
};

// Function to Build Tree from space-separated input
Node* buildTree(const string& str) {
    if (str.empty() || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string val; iss >> val;) 
        ip.push_back(val);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;

    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;

        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int main() {
    cout << "Enter tree elements as space-separated values (use 'N' for NULL nodes):\n";
    string s;
    getline(cin, s);

    Node* root = buildTree(s);
    Solution ob;
    
    if (ob.isBST(root))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}

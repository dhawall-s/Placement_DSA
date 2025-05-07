#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to build a binary tree from a string representation
Node* buildTree(string str) {
    if (str.empty() || str[0] == 'N') return nullptr;
    
    // Create the root node
    stringstream ss(str);
    string item;
    getline(ss, item, ' ');
    Node* root = new Node(stoi(item));
    
    // Queue for level order construction
    queue<Node*> q;
    q.push(root);
    
    // Iterate over the remaining nodes
    while (!ss.eof()) {
        Node* current = q.front();
        q.pop();
        
        // Left child
        if (getline(ss, item, ' ')) {
            if (item != "N") {
                current->left = new Node(stoi(item));
                q.push(current->left);
            }
        }
        
        // Right child
        if (getline(ss, item, ' ')) {
            if (item != "N") {
                current->right = new Node(stoi(item));
                q.push(current->right);
            }
        }
    }
    
    return root;
}

class Solution {
public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> currentPath;
        findPaths(root, currentPath, result);
        return result;
    }
    
private:
    void findPaths(Node* node, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return;  // Base case: if node is null, return
        
        // Add current node to the path
        currentPath.push_back(node->data);
        
        // If it's a leaf node, add the path to the result
        if (!node->left && !node->right) {
            result.push_back(currentPath);
        } else {
            // Recur for the left and right subtrees
            findPaths(node->left, currentPath, result);
            findPaths(node->right, currentPath, result);
        }
        
        currentPath.pop_back();
    }
};

void printPaths(vector<vector<int>> paths) {
    for (auto path : paths) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    
    string tree1 = "1 2 3 4 5 N N";
    Node* root1 = buildTree(tree1);
    Solution sol;
    vector<vector<int>> paths1 = sol.Paths(root1);
    cout << "Paths for tree 1:" << endl;
    printPaths(paths1);

    
    string tree2 = "10 20 30 40 60 N N";
    Node* root2 = buildTree(tree2);
    vector<vector<int>> paths2 = sol.Paths(root2);
    cout << "\nPaths for tree 2:" << endl;
    printPaths(paths2);

    string tree3 = "1 2 3";
    Node* root3 = buildTree(tree3);
    vector<vector<int>> paths3 = sol.Paths(root3);
    cout << "\nPaths for tree 3:" << endl;
    printPaths(paths3);

    return 0;
}

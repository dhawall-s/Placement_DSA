#include<iostream>
#include<climits> // For INT_MIN and INT_MAX
using namespace std;

class T {
public:
    int val;
    T* l;
    T* r;
    T(int value) {
        val = value;
        l = nullptr;
        r = nullptr;
    }
};

T* insert(T* root, int val) {
    if (root == nullptr) {
        return new T(val);
    }
    if (val < root->val) {
        root->l = insert(root->l, val);
    } else {
        root->r = insert(root->r, val);
    }
    return root;
}

void in(T* root) {
    if (root == nullptr) return;
    in(root->l);
    cout << root->val << " ";
    in(root->r);
}

bool isBSTUtil(T* root, int minVal, int maxVal) {
    if (root == nullptr) return true;

    if (root->val <= minVal || root->val >= maxVal)
        return false;

    return isBSTUtil(root->l, minVal, root->val) &&
           isBSTUtil(root->r, root->val, maxVal);
}

bool isBST(T* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    int n;
    cout << "Enter the no. of elements: ";
    cin >> n;
    T* root = nullptr;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder Traversal: ";
    in(root);
    cout << endl;

    if (isBST(root)) {
        cout << "The tree is a BST.\n";
    } else {
        cout << "The tree is NOT a BST.\n";
    }

    return 0;
}

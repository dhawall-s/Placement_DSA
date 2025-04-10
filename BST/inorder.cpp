#include<iostream>
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
    return 0;
}

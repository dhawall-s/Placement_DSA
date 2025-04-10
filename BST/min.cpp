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
int findMin(T* root) {
     while (root->l != nullptr) {
        root = root->l;
    }
    return root->val;
    
}
int main() {
    int n;
    cin >> n;
    T* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    cout << findMin(root);
    return 0;
}

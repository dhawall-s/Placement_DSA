#include<iostream>
using namespace std;
class Node {
public:
    int d;
    Node* l;
    Node* r;

    Node(int val) {
        d = val;
        l = nullptr;
        r = nullptr;
    }
};

class b {
public:
    static Node* cB(int arr[], int s, int e) {
        if (s > e) {
            return nullptr;
        }
        int m = (s + e) / 2;
        Node* root = new Node(arr[m]);
        root->l = cB(arr, s, m - 1);
        root->r = cB(arr, m + 1, e);
        return root;
    }
    static void p(Node* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->d << " ";
        p(root->l);
        p(root->r);
    }
};
int main() {
    int n;
    cin >> n;              
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];     
    }
    Node* root = b::cB(arr, 0, n - 1);
    b::p(root);             
    return 0;
}

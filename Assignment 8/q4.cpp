#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node* left;
    Node* right;
    int val;
    Node(int value=0) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

bool isBstHelper(Node* root, int min, int max) {
    if (!root) return true;

    if (root->val < min || root->val > max) return false;

    return isBstHelper(root->left, min, root->val-1) && isBstHelper(root->right, root->val+1, max);
    
}

bool isBST(Node* root) {
    return isBstHelper(root, INT_MIN, INT_MAX);
}
int main() {
    Node* root = new Node(10);

    root->left = new Node(11);
    root->right = new Node(20);

    root->left->left = new Node(3);
    root->left->right = new Node(7);

    root->right->left = new Node(15);
    root->right->right = new Node(30);

    cout << isBST(root);

    return 0;
}

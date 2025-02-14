#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    void inorder(Node* root, Node*& prev, Node*& first, Node*& second) {
        if (root == NULL) return;
        inorder(root->left, prev, first, second);
        if (prev && prev->val > root->val) {
            if (first == NULL) first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right, prev, first, second);
    }

    void correctBST(Node* root) {
        Node* prev = NULL;
        Node* first = NULL;
        Node* second = NULL;
        inorder(root, prev, first, second);
        if (first && second) swap(first->val, second->val);
    }
};
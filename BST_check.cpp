#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
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
    void inorder(Node* root, int& prev, bool& flag) {
        if (root == NULL) return;
        inorder(root->left, prev, flag);
        if (root->data <= prev) {
            flag = false;
            return;
        }
        prev = root->data;
        inorder(root->right, prev, flag);
    }

    bool isBST(Node* root) {
        int prev = INT_MIN;
        bool flag = true;
        inorder(root, prev, flag);
        return flag;
    }
};

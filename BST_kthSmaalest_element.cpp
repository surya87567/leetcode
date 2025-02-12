#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    void kthSmallestUtil(Node* root, int k, int &count, int &ans) {
        if (root == NULL) return;

        kthSmallestUtil(root->left, k, count, ans);

        count++; 
        if (count == k) {
            ans = root->data;
            return;
        }

        kthSmallestUtil(root->right, k, count, ans);
    }

    int kthSmallest(Node *root, int k) {
        int count = 0, ans = -1;
        kthSmallestUtil(root, k, count, ans);
        return ans;
    }
};

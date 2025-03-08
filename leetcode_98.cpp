#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& temp) {
        if (root == NULL) return;
        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> temp;
        inorder(root, temp);
        for (int i = 0; i < temp.size() - 1; i++) {
            if (temp[i] >= temp[i + 1]) return false;
        }
        return true;
    }
};
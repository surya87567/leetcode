#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void trim(TreeNode* root, int l, int h) {
        if (root == NULL) return;
        
        while (root->left != NULL) {
            if (root->left->val < l) root->left = root->left->right;
            else if (root->left->val > h) root->left = root->left->left;
            else break;
        }
        
        while (root->right != NULL) {
            if (root->right->val > h) root->right = root->right->left;
            else if (root->right->val < l) root->right = root->right->right;
            else break;
        }
        
        trim(root->left, l, h);
        trim(root->right, l, h);
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        trim(dummy, low, high);
        return dummy->left;
    }
};

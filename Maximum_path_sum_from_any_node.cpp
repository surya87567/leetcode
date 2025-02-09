#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSumUtil(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        int leftSum = max(0, maxPathSumUtil(root->left, maxSum));
        int rightSum = max(0, maxPathSumUtil(root->right, maxSum));
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        return root->val + max(leftSum, rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumUtil(root, maxSum);
        return maxSum;
    }
};

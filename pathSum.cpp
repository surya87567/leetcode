#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* root, long long sum, int &count) {
        if (root == NULL) return;
        if ((long long)(root->val) == sum) {
            count++;
        }
        helper(root->left, sum - root->val, count);
        helper(root->right, sum - root->val, count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        int count = 0;
        helper(root, (long long)(targetSum), count);
        count += pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        return count;
    }
};

TreeNode* buildTree(const vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }
    TreeNode* root = new TreeNode(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);
    return root;
}

int main() {
    vector<int> nodes = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
    int index = 0;
    TreeNode* root = buildTree(nodes, index);
    
    Solution sol;
    int targetSum = 22;
    cout << "Number of paths: " << sol.pathSum(root, targetSum) << endl;

    return 0;
}
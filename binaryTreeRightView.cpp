#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void rightView(TreeNode* root, vector<int>& ans, int n, int& x) {
        if (root == NULL)
            return;
        if (n == x) {
            ans.push_back(root->val);
            x++;
        }
        rightView(root->right, ans, n + 1, x);
        rightView(root->left, ans, n + 1, x);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int x = 0;
        rightView(root, ans, 0, x);
        return ans;
    }
};

void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);
    printVector(result);

    return 0;
}

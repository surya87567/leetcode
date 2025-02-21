#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
    unordered_set<int> nodes;

    void recover(TreeNode* root, int val) {
        if (!root) return;
        root->val = val;
        nodes.insert(val);
        recover(root->left, 2 * val + 1);
        recover(root->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        recover(root, 0);
    }

    bool find(int target) {
        return nodes.count(target);
    }
};

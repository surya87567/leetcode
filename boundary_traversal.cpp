#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "N") return NULL;
    
    Node* root = new Node(stoi(nodes[0]));
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* current = q.front();
        q.pop();
        
        if (nodes[i] != "N") {
            current->left = new Node(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != "N") {
            current->right = new Node(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

class Solution {
public:
    void leftBoundary(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return;
        ans.push_back(root->data);
        leftBoundary(root->left, ans);
        if (root->left == NULL) leftBoundary(root->right, ans);
    }

    void bottomBoundary(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) ans.push_back(root->data);
        bottomBoundary(root->left, ans);
        bottomBoundary(root->right, ans);
    }

    void rightBoundary(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return;
        if (root->right == NULL) rightBoundary(root->left, ans);
        rightBoundary(root->right, ans);
        ans.push_back(root->data);
    }

    void boundary(Node* root, vector<int>& ans) {
        leftBoundary(root->left, ans);
        bottomBoundary(root, ans);
        rightBoundary(root->right, ans);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        ans.push_back(root->data);
        if (root->left == NULL && root->right == NULL) return ans;
        boundary(root, ans);
        return ans;
    }
};

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<string> nodes;
    string node;
    while (ss >> node) {
        nodes.push_back(node);
    }
    
    Node* root = buildTree(nodes);
    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

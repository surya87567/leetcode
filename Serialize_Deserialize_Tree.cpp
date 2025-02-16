#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to serialize the tree into an array
vector<int> serialize(Node* root) {
    vector<int> a;
    if (!root) return a;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if (curr) {
            a.push_back(curr->data);
            q.push(curr->left);
            q.push(curr->right);
        } else {
            a.push_back(-1);
        }
    }
    return a;
}

// Function to deserialize the array into a tree
Node* deSerialize(vector<int>& a) {
    if (a.empty()) return nullptr;
    
    Node* root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if (i < a.size() && a[i] != -1) {
            curr->left = new Node(a[i]);
            q.push(curr->left);
        }
        i++;
        
        if (i < a.size() && a[i] != -1) {
            curr->right = new Node(a[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

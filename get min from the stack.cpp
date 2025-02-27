#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    stack<int> s, minStack;

    Solution() {}

    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!s.empty()) {
            if (s.top() == minStack.top()) {
                minStack.pop();
            }
            s.pop();
        }
    }

    int peek() {
        if (s.empty()) {
            return -1;
        }
        return s.top();
    }

    int getMin() {
        if (minStack.empty()) {
            return -1;
        }
        return minStack.top();
    }
};

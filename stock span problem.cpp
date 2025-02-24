#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& prices) {
        vector<int> span(prices.size());
        stack<int> st;
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] <= prices[i]) {
                st.pop();
            }
            if (st.empty()) {
                span[i] = i + 1;
            } else {
                span[i] = i - st.top();
            }
            st.push(i);
        }
        return span;
    }
};

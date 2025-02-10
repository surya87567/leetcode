#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        int n = s.size();
        int x;
        for (int i = 0; i < n; i++) {
            x = s[i] - '0';
            if (x >= 0 && x <= 9 && !st.empty()) 
                st.pop();
            else 
                st.push(s[i]);
        }
        string str = "";
        while (!st.empty()) {
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};
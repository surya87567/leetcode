#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string str = "";
        int n = s.size(), m = part.size();
        for (int i = 0; i < n; i++) {
            str += s[i];
            if (str.size() >= m && str.substr(str.size() - m, m) == part) {
                for (int j = 0; j < m; j++) {
                    str.pop_back();
                }
            }
        }
        return str;
    }
};
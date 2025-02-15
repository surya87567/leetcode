#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(string s, int target, int sum, int index) {
        if (index == s.size()) return sum == target;
        int num = 0;
        for (int i = index; i < s.size(); ++i) {
            num = num * 10 + (s[i] - '0');
            if (backtrack(s, target, sum + num, i + 1)) return true;
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            string square = to_string(i * i);
            if (backtrack(square, i, 0, 0)) result += i * i;
        }
        return result;
    }
};

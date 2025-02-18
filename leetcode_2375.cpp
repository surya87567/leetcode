#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string smallestNumber(string pattern) {
        string num, stack;
        for (int i = 0; i <= pattern.size(); i++) {
            stack += ('1' + i);
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!stack.empty()) {
                    num += stack.back();
                    stack.pop_back();
                }
            }
        }
        return num;
    }
};

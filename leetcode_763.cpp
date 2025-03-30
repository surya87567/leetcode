#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
      vector<int> partitionLabels(string s) {
          vector<int> lastIndex(26, 0);
          vector<int> ans;
  
          for(int i = 0; i < s.size(); i++) {
              lastIndex[s[i] - 'a'] = i;
          }
  
          int maxEnd = 0, prevEnd = -1;
          for(int i = 0; i < s.size(); i++) {
              maxEnd = max(maxEnd, lastIndex[s[i] - 'a']);
              if(i == maxEnd) {  
                  ans.push_back(i - prevEnd);  
                  prevEnd = i;
              }
          }
          return ans;
      }
  };
  
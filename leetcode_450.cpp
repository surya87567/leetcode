#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
  public:
      int numberOfSubstrings(string s) {
          int n = s.size();
          unordered_map<char, int> mp;
          int cnt = 0;
          int i = 0, j = 0;
          while (j < n) {
              mp[s[j]]++;
                  while (mp.size() == 3) {
                      cnt += n - j;
                      mp[s[i]]--;
                      if (mp[s[i]] == 0)
                          mp.erase(s[i]);
                      i++;
                  }
              j++;
          }
          return cnt;
      }
  };
  
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
      int minimumIndex(vector<int>& nums) {
          unordered_map<int, int> mp;
          int n = nums.size();
          for (auto num : nums) {
              mp[num]++;
          }
          int ele;
          int mx = INT_MIN;
          for (auto it : mp) {
              if (mx < it.second) {
                  mx = it.second;
                  ele = it.first;
              }
          }
          int i, count = 0;
          for (i = 0; i < n; i++) {
              if (nums[i] == ele) {
                  count++;
                  if (count > (i + 1) / 2 && (mx - count) > (n - i - 1) / 2) break;
              }
          }
          if (i != n) return i;
          else return -1;
      }
  };
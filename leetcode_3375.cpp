#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
      int minOperations(vector<int>& nums, int k) {
          int n = nums.size();
          unordered_map<int, int> mp;
          int mn = INT_MAX;
  
          for (int i = 0; i < n; i++) {
              mp[nums[i]]++;
              mn = min(mn, nums[i]);
          }
          int ans;
          if (k > mn) ans = -1;
          if (k < mn) ans = mp.size();
          if (k == mn) ans = mp.size() - 1;
  
          return ans;
      }
  };
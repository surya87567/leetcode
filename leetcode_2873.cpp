#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
      long long maximumTripletValue(vector<int>& nums) {
          int n = nums.size();
          long long mxVal = 0, temp;
          for (int i = 0; i < n; i++) {
              for (int j = i + 1; j < n; j++) {
                  for (int k = j + 1; k < n; k++) {
                      temp = (long long)(nums[i] - nums[j]) * nums[k];
                      mxVal = max(mxVal, temp);
                  }
              }
          }
          return mxVal;
      }
  };
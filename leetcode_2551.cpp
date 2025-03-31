#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
      long long putMarbles(vector<int>& weights, int k) {
          long long minSum = 0;
          long long maxSum = 0;
          int n = weights.size();
          vector<long long> temp(n - 1, 0);
          for (int i = 0; i < n - 1; i++) {
              temp[i] = weights[i] + weights[i + 1];
          }
  
          sort(temp.begin(), temp.end());
          for (int j = 0; j < k - 1; j++) {
              minSum += temp[j];
              maxSum += temp[n - 2 - j];
          }
  
          return maxSum - minSum;
      }
  };
  
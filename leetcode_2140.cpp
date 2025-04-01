#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
      long long solve(int n, int i, vector<vector<int>>& q, vector<long long>& t) {
          if (i >= n) return 0;
          if (t[i] != -1) return t[i];
          long long taken = q[i][0] + solve(n, i + q[i][1] + 1, q, t);
          long long notTaken = solve(n, i + 1, q, t);
          return t[i] = max(taken, notTaken);
      }
      
      long long mostPoints(vector<vector<int>>& q) {
          int n = q.size();
          vector<long long> t(n + 1, -1);
          return solve(n, 0, q, t);
      }
  };
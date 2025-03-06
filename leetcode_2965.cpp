#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
      vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
          unordered_map<int, int> mp;
          int n = grid.size();
          int sum = 0;
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < n; j++) {
                  mp[grid[i][j]]++;
                  sum += grid[i][j];
              }
          }
          int x = n * n;
          int nSum = (x * (x + 1)) / 2;
          int a = 0, b = 0;
          for (auto it : mp) {
              if (it.second > 1) a = it.first;
          }
          sum = sum - a;
          b = nSum - sum;
          return {a, b};
      }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        int n = grid.size();
        int m = grid[0].size();
        int r = grid[0][0] % x;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] % x != r) return -1;
                temp.push_back(grid[i][j]);
            }
        }

        sort(temp.begin(), temp.end());
        int median = temp[temp.size() / 2]; // Using median
        int ans = 0;

        for (int num : temp) {
            ans += abs(num - median) / x;
        }

        return ans;
    }
};

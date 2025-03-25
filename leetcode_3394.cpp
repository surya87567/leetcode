#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> axisX, axisY;
        for (const auto& rect : rectangles) {
            axisX.push_back({rect[0], rect[2]});
            axisY.push_back({rect[1], rect[3]});
        }

        int xIntervals = merge(axisX).size();
        int yIntervals = merge(axisY).size();

        return xIntervals >= 3 || yIntervals >= 3;
    }
};

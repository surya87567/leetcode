#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> hp;
        vector<vector<int>> ans;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            if (hp.size() <= k) {
                hp.push({x, points[i]});
            }
            if (hp.size() > k) hp.pop();
        }
        while (!hp.empty()) {
            ans.push_back(hp.top().second);
            hp.pop();
        }
        return ans;
    }
};

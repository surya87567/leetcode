#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Using binary search to optimize the solution
    bool check(vector<int>& candies, int mid, long long k) {
        long long count = 0;
        for (int i = 0; i < candies.size(); i++) {
            count += candies[i] / mid;
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;
        int maxC = INT_MIN;
        int n = candies.size();
        
        for (int i = 0; i < n; i++) {
            total += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if (total < k)
            return 0;

        int ans = 0, l = 1, r = maxC;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(candies, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

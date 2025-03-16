#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    bool check(vector<int>& ranks, int cars, long long mid) {
        long long count = 0;
        for (int i = 0; i < ranks.size(); i++) {
            count += sqrt(mid / ranks[i]);
        }
        return count >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long x = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (ranks[i] > x)
                x = ranks[i];
        }
        long long ans;
        long long l = 1;
        long long h = x * cars * cars;
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (check(ranks, cars, mid)) {
                ans = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};

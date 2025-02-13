#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> hp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            hp.push(nums[i]);
        }
        int count = 0;
        long long a, b;
        while (!hp.empty()) {
            if (hp.top() >= k)
                break;
            a = hp.top();
            hp.pop();
            b = hp.top();
            hp.pop();
            hp.push(2 * min(a, b) + max(a, b));
            count++;
        }
        return count;
    }
};
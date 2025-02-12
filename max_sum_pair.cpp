#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mp;
        int maxSum = -1;
        
        for (int num : nums) {
            int sum = 0, x = num;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            mp[sum].push(num);
        }

        for (auto& it : mp) {
            if (it.second.size() > 1) {
                int Sum = it.second.top(); 
                it.second.pop();
                Sum += it.second.top();
                maxSum = max(maxSum, Sum);
            }
        }

        return maxSum;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long totalPairs = (long long)n * (n - 1) / 2;
        long long goodPairs = 0;
        
        for (int i = 0; i < n; i++) {
            goodPairs += freq[i - nums[i]];
            freq[i - nums[i]]++;
        }
        
        return totalPairs - goodPairs;
    }
};

int main() {
    vector<int> nums = {4, 1, 3, 3};
    Solution sol;
    cout << sol.countBadPairs(nums) << endl;
    return 0;
}
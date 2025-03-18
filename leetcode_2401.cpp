#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSize = 0, bits = 0, i = 0;
        for (int j = 0; j < n; j++) {
            while ((bits & nums[j]) != 0) { 
                bits ^= nums[i]; 
                i++;
            }
            bits |= nums[j]; 
            maxSize = max(maxSize, j - i + 1);
        }
        return maxSize;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0, count = 0;
        while (i + 2 < n) {
            if (nums[i] == 0) {
                for (int j = i; j <= i + 2; j++) {
                    nums[j] = (nums[j] == 0) ? 1 : 0;
                }
                count++;
            }
            i++;
        }
        int countOnes = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == 1) countOnes++;
        }
        return (countOnes == n) ? count : -1;
    }
};

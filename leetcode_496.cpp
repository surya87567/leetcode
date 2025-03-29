#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) break;
            }
            while (j < m) {
                if (nums1[i] < nums2[j]) {
                    ans.push_back(nums2[j]);
                    break;
                }
                j++;
            }
            if (j == m) ans.push_back(-1);
        }
        return ans;
    }
};

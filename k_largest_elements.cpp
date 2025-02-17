#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kLargest(vector<int>& arr, int k) {
        vector<int> ans;
        int n = arr.size();
        priority_queue<int> hp;
        for (int i = 0; i < n; i++) {
            hp.push(arr[i]);
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(hp.top());
            hp.pop();
        }
        return ans;
    }
};

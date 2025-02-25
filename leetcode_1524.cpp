#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1, sum = 0, mod = 1e9 + 7, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum = (sum + arr[i]) % 2;
            res = (res + (sum ? even : odd)) % mod;
            if (sum) odd++;
            else even++;
        }
        return res;
    }
};

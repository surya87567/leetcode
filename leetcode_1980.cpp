#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, bool> numMap;
        for (const string& num : nums) {
            numMap[num] = true;
        }
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            string candidate = "";
            for (int j = 0; j < n; j++) {
                candidate += (i & (1 << j)) ? '1' : '0';
            }
            if (numMap.find(candidate) == numMap.end()) {
                return candidate;
            }
        }
        return "";
    }
};
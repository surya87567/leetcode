#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = 0, posCount = 0;
        for (int num : nums) {
            if (num < 0) negCount++;
            if (num > 0) posCount++;
        }
        return max(negCount, posCount);
    }
};

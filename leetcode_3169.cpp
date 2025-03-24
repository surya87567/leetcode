#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int start = 0;
        int end = 0;
        int ans = 0;
        for (int i = 0; i < meetings.size(); i++) {
            if (meetings[i][0] > end) {
                ans += meetings[i][0] - end - 1;
            }
            end = max(end, meetings[i][1]);
        }
        if (days > end) {
            ans += days - end;
        }
        return ans;
    }
};

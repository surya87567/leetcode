#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), ans = 0, count = 1;
        for(int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] != colors[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count >= k) {
                ans++;
            }
        }
        return ans;
    }
};
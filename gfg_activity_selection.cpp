#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hp;
        for (int i = 0; i < start.size(); i++) {
            hp.push({finish[i], start[i]});
        }
        int count = 1;
        int s = hp.top().second;
        int f = hp.top().first;
        hp.pop();
        while (!hp.empty()) {
            if (hp.top().second > f) {
                count++;
                s = hp.top().second;
                f = hp.top().first;
            }
            hp.pop();
        }
        return count;
    }
};

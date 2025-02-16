#include <vector>
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& res, vector<bool>& used, int n, int idx) {
        if (idx == res.size()) return true;
        if (res[idx] != 0) return backtrack(res, used, n, idx + 1);
        
        for (int num = n; num >= 1; --num) {
            if (used[num]) continue;
            int secondIdx = (num == 1 ? idx : idx + num);
            
            if (secondIdx < res.size() && res[secondIdx] == 0) {
                res[idx] = res[secondIdx] = num;
                used[num] = true;
                
                if (backtrack(res, used, n, idx + 1)) return true;
                
                res[idx] = res[secondIdx] = 0;
                used[num] = false;
            }
        }
        
        return false;
    }
    
    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(res, used, n, 0);
        return res;
    }
};

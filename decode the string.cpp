#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodedString(string &s) {
        stack<int> counts;
        stack<string> result;
        string res;
        int i = 0, n = s.size();
        while (i < n) {
            if (isdigit(s[i])) {
                int count = 0;
                while (isdigit(s[i])) count = count * 10 + (s[i++] - '0');
                counts.push(count);
            } else if (s[i] == '[') {
                result.push(res);
                res = "";
                i++;
            } else if (s[i] == ']') {
                string temp = res;
                res = result.top();
                result.pop();
                int count = counts.top();
                counts.pop();
                while (count--) res += temp;
                i++;
            } else {
                res += s[i++];
            }
        }
        return res;
    }
};

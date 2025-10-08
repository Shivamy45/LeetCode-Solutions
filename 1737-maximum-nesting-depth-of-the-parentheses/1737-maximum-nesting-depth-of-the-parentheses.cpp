class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cnt = 0;
        for (char c : s) {
            if (c == '(')
                cnt++;
            else if (c == ')')
                cnt--;
            res = max(res, cnt);
        }
        return res;
    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length(), m = goal.length();
        if (n != m)
            return false;
        s += s;
        for (int i = 0; i < n; i++) {
            string subStr = s.substr(i, m);
            if (subStr == goal)
                return true;
        }
        return false;
    }
};
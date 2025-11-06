class Solution {
public:
    void helperValidString(int n, string s, vector<string>& res) {
        if (s.size() == n) {
            res.push_back(s);
            return;
        }
        if (s.empty() || s.back() != '0')
            helperValidString(n, s + '0', res);
        helperValidString(n, s + '1', res);
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        helperValidString(n, "", res);
        return res;
    }
};
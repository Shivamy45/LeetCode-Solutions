class Solution {
public:
    void helperValidString(int n, string &s, vector<string>& res) {
        if (s.size() == n) {
            res.push_back(s);
            return;
        }
        if (s.empty() || s.back() != '0'){
            s.push_back('0');
            helperValidString(n, s, res);
            s.pop_back();
        }
        s.push_back('1');
        helperValidString(n, s, res);
        s.pop_back();
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        string temp;
        helperValidString(n, temp, res);
        return res;
    }
};
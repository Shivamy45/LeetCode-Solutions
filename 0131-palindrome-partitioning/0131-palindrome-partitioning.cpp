class Solution {
public:
    bool checkPalindrome(string x) {
        int n = x.size();
        for (int i = 0; i < n / 2; i++)
            if (x[i] != x[n - i - 1])
                return false;
        return true;
    }

    void helperPartition(string s, vector<vector<string>>& res,
                         vector<string>& temp, int idx) {
        if (idx == s.length()) {
            res.push_back(temp);
            return;
        }
        string cmp = "";
        for (int i = idx; i < s.length(); i++) {
            cmp += s[i];
            if (checkPalindrome(cmp)) {
                temp.push_back(cmp);
                helperPartition(s, res, temp, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        helperPartition(s, res, temp, 0);
        return res;
    }
};
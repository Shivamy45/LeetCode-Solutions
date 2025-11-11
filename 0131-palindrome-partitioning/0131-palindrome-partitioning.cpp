class Solution {
public:
    void helperPartition(string& s, vector<vector<string>>& res,
                         vector<string>& temp, int idx,
                         vector<vector<bool>>& isPP) {
        if (idx == s.length()) {
            res.push_back(temp);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            if (isPP[idx][i]) {
                temp.push_back(s.substr(idx, i - idx + 1));
                helperPartition(s, res, temp, i + 1, isPP);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        vector<vector<bool>> isPP(s.length(), vector<bool>(s.length(), false));
        for (int i = s.length() - 1; i >= 0; i--)
            for (int j = i; j < s.length(); j++)
                isPP[i][j] = (s[i] == s[j] && (j - i < 2 || isPP[i + 1][j - 1]));
        helperPartition(s, res, temp, 0, isPP);
        return res;
    }
};
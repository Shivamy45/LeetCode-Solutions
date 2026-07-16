class Solution {
public:
    bool helperWordBreak(string& s, unordered_set<string>& words, int idx,
                         vector<int>& dp) {
        if (idx == s.length())
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        for (int i = idx; i < s.length(); i++) {
            string word = s.substr(idx, i - idx + 1);
            if (words.count(word) && helperWordBreak(s, words, i + 1, dp)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words{begin(wordDict), end(wordDict)};
        vector<int> dp(s.length(), -1);
        return helperWordBreak(s, words, 0, dp);
    }
};
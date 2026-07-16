class Solution {
public:
    bool helperWordBreak(string& s, unordered_set<string>& words, int idx,
                     vector<int>& dp, int maxLen) {
    if (idx == s.length()) return true;
    if (dp[idx] != -1) return dp[idx];
    for (int i = idx; i < s.length(); i++) {
        if (i - idx + 1 > maxLen) break;
        string word = s.substr(idx, i - idx + 1);
        if (words.count(word) && helperWordBreak(s, words, i + 1, dp, maxLen)) {
            return dp[idx] = true;
        }
    }
    return dp[idx] = false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words{begin(wordDict), end(wordDict)};
    int maxLen = 0;
    for (string a : words) maxLen = max(maxLen, (int)a.length());
    vector<int> dp(s.length(), -1);
    return helperWordBreak(s, words, 0, dp, maxLen);
}
};
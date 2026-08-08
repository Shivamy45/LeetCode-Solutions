class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int mismatch = 0;
        int n = word1.length(), m = word2.length();
        vector<int> suffix(n);
        int j = m - 1, matched = 0;
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = matched;
            if (j >= 0 && word1[i] == word2[j]) {
                matched++;
                j--;
            }
        }
        j = 0;
        vector<int> ans;
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                j++;
                ans.push_back(i);
            } else if (mismatch == 0 && suffix[i] >= m - j - 1) {
                mismatch = 1;
                j++;
                ans.push_back(i);
            }
            if (ans.size() == m)
                return ans;
        }
        return {};
    }
};
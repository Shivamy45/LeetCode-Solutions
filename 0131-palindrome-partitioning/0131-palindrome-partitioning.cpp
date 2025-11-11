class Solution {
public:
    // Backtracking function to build partitions
    void backtrack(int index, string& s, vector<string>& path,
                   vector<vector<string>>& res, vector<vector<bool>> &isPP) {
        // If index reaches end of string, store current partition
        if (index == s.length()) {
            res.push_back(path);
            return;
        }

        // Try all possible substrings
        for (int i = index; i < s.length(); i++) {
            // If substring is a palindrome
            if (isPP[index][i]) {
                // Add substring to current path
                path.push_back(s.substr(index, i - index + 1));
                // Recur for remaining string
                backtrack(i + 1, s, path, res, isPP);
                // Backtrack to try other partitions
                path.pop_back();
            }
        }
    }

    // Main function to return all palindrome partitions
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> path;
        vector<vector<bool>> isPP(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                isPP[i][j] =
                    (s[i] == s[j] && (j - i < 2 || isPP[i + 1][j - 1]));
        backtrack(0, s, path, res, isPP);
        return res;
    }
};
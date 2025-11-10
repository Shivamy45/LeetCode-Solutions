class Solution {
public:
    bool helperExist(vector<vector<char>>& board, string &word, int i, int j,
                     int idx, int n, int m) {
        if (idx == word.length())
            return true;
        if (i >= n || i < 0 || j >= m || j < 0)
            return false;
        if (word[idx] != board[i][j])
            return false;
        char saved = board[i][j];
        board[i][j] = '#';
        bool found = helperExist(board, word, i + 1, j, idx + 1, n, m) ||
                     helperExist(board, word, i, j + 1, idx + 1, n, m) ||
                     helperExist(board, word, i - 1, j, idx + 1, n, m) ||
                     helperExist(board, word, i, j - 1, idx + 1, n, m);
        board[i][j] = saved;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (helperExist(board, word, i, j, 0, n, m))
                    return true;
        return false;
    }
};
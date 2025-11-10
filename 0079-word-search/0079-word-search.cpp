class Solution {
public:
    bool helperExist(vector<vector<char>>& board, string &word, int i, int j,
                     int idx) {
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
            return false;
        if (word[idx] != board[i][j])
            return false;
        if (idx == word.size() - 1)
            return true;
        char saved = board[i][j];
        board[i][j] = '#';
        bool found = helperExist(board, word, i + 1, j, idx + 1) ||
                     helperExist(board, word, i, j + 1, idx + 1) ||
                     helperExist(board, word, i - 1, j, idx + 1) ||
                     helperExist(board, word, i, j - 1, idx + 1);
        board[i][j] = saved;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (helperExist(board, word, i, j, 0))
                    return true;
        return false;
    }
};
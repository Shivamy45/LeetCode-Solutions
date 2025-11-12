class Solution {
public:
    bool isSafe(vector<string>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Q') {
                    for (int x = i + 1; x < n; x++)
                        if (board[x][j] == 'Q')
                            return false;
                    for (int x = j + 1; x < n; x++)
                        if (board[i][x] == 'Q')
                            return false;
                    for (int x = 1; x + i < n && x + j < n; x++)
                        if (board[i + x][j + x] == 'Q')
                            return false;
                    for (int x = 1; x + i < n && j - x >= 0; x++)
                        if (board[i + x][j - x] == 'Q')
                            return false;
                }
            }
        }
        return true;
    }

    void helperSolveNQueens(vector<vector<string>>& res, vector<string>& board,
                            int curr, int n) {
        if (curr == n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            board[curr][i] = 'Q';
            if (isSafe(board))
                helperSolveNQueens(res, board, curr + 1, n);
            board[curr][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        helperSolveNQueens(res, board, 0, n);
        return res;
    }
};
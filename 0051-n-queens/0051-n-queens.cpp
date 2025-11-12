class Solution {
public:
    void helperSolveNQueens(vector<vector<string>>& res, vector<string>& board,
                            int col, int n, vector<bool>& left,
                            vector<bool>& lowerDiag, vector<bool>& upperDiag) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (!(upperDiag[n - 1 + col - row] || lowerDiag[row + col] ||
                  left[row])) {
                left[row] = lowerDiag[row + col] =
                    upperDiag[n - 1 + col - row] = true;
                board[row][col] = 'Q';
                helperSolveNQueens(res, board, col + 1, n, left, lowerDiag,
                                   upperDiag);
                board[row][col] = '.';
                upperDiag[n - 1 + col - row] = lowerDiag[row + col] =
                    left[row] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> left(n, false);
        vector<bool> lowerDiag(n * 2 + 1, false);
        vector<bool> upperDiag(n * 2 + 1, false);
        helperSolveNQueens(res, board, 0, n, left, lowerDiag, upperDiag);
        return res;
    }
};
class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int rowCopy = row, colCopy = col;
        // left
        while (colCopy >= 0) {
            if (board[row][colCopy] == 'Q')
                return false;
            colCopy--;
        }
        // upper diag
        colCopy = col;
        while (rowCopy >= 0 && colCopy >= 0) {
            if (board[rowCopy][colCopy] == 'Q')
                return false;
            rowCopy--;
            colCopy--;
        }
        rowCopy = row;
        colCopy = col;
        while (rowCopy < board.size() && colCopy >= 0) {
            if (board[rowCopy][colCopy] == 'Q')
                return false;
            rowCopy++;
            colCopy--;
        }
        return true;
    }

    void helperSolveNQueens(vector<vector<string>>& res, vector<string>& board,
                            int col, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                helperSolveNQueens(res, board, col + 1, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    helperSolveNQueens(res, board, 0, n);
    return res;
}
};
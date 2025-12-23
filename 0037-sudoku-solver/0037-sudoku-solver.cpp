class Solution {
public:
    bool isPossible(vector<vector<char>>& board, int x, int y, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == c)
                return false;
            if (board[x][i] == c)
                return false;
            if (board[3 * (x / 3) + i / 3][3 * (y / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    bool helperSolveSodoku(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;
        else if (col == 9)
            return helperSolveSodoku(board, row + 1, 0);
        else if (board[row][col] != '.')
            return helperSolveSodoku(board, row, col + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (isPossible(board, row, col, c)) {
                board[row][col] = c;
                if (helperSolveSodoku(board, row, col + 1))
                    return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helperSolveSodoku(board, 0, 0);
    }
};
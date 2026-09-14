class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                visited[i][m - 1] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                visited[0][i] = 1;
            }
            if (board[n - 1][i] == 'O') {
                q.push({n - 1, i});
                visited[n - 1][i] = 1;
            }
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                if (i + 1 < n && board[i + 1][j] == 'O' && !visited[i + 1][j]) {
                    q.push({i + 1, j});
                    visited[i + 1][j] = 1;
                }
                if (i > 0 && board[i - 1][j] == 'O' && !visited[i - 1][j]) {
                    q.push({i - 1, j});
                    visited[i - 1][j] = 1;
                }
                if (j > 0 && board[i][j - 1] == 'O' && !visited[i][j - 1]) {
                    q.push({i, j - 1});
                    visited[i][j - 1] = 1;
                }
                if (j + 1 < m && board[i][j + 1] == 'O' && !visited[i][j + 1]) {
                    q.push({i, j + 1});
                    visited[i][j + 1] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
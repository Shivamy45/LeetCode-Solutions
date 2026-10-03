class Solution {
public:
    int checkBfsNumEnclaves(vector<vector<int>>& grid,
                             vector<vector<int>>& visited, int i1, int j1,
                             int n, int m) {
        bool flag = true;
        queue<pair<int, int>> q;
        int ans = 0;
        q.push({i1, j1});
        visited[i1][j1] = 1;
        while (!q.empty()) {
            int size = q.size();
            ans += size;
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                    flag = false;
                if (i > 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
                    q.push({i - 1, j});
                    visited[i - 1][j] = 1;
                }
                if (i + 1 < n && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
                    q.push({i + 1, j});
                    visited[i + 1][j] = 1;
                }

                if (j > 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
                    q.push({i, j - 1});
                    visited[i][j - 1] = 1;
                }
                if (j + 1 < m && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
                    q.push({i, j + 1});
                    visited[i][j + 1] = 1;
                }
            }
        }
        return (flag) ? ans : 0;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int enclaves = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j])
                    enclaves += checkBfsNumEnclaves(grid, visited, i, j, n, m);
            }
        }
        return enclaves;
    }
};
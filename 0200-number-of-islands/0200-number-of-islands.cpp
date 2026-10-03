class Solution {
public:
    void bfsNumIslands(vector<vector<char>>& grid, vector<vector<int>>& visited,
                       int i1, int j1, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i1, j1});
        visited[i1][j1] = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                if (i > 0 && grid[i - 1][j] == '1' && !visited[i - 1][j]) {
                    q.push({i - 1, j});
                    visited[i - 1][j] = 1;
                }
                if (i + 1 < m && grid[i + 1][j] == '1' && !visited[i + 1][j]) {
                    q.push({i + 1, j});
                    visited[i + 1][j] = 1;
                }

                if (j > 0 && grid[i][j - 1] == '1' && !visited[i][j - 1]) {
                    q.push({i, j - 1});
                    visited[i][j - 1] = 1;
                }
                if (j + 1 < n && grid[i][j + 1] == '1' && !visited[i][j + 1]) {
                    q.push({i, j + 1});
                    visited[i][j + 1] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfsNumIslands(grid, visited, i, j, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};
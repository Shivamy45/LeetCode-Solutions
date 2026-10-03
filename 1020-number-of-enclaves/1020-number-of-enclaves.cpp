class Solution {
public:
    void dfsNumEnclaves(vector<vector<int>>& grid, vector<vector<int>>& visited,
                        int i, int j, int n, int m) {
        if (i < 0 || i == n || j < 0 || j == m || visited[i][j] ||
            grid[i][j] == 0)
            return;
        visited[i][j] = 1;
        dfsNumEnclaves(grid, visited, i - 1, j, n, m);
        dfsNumEnclaves(grid, visited, i + 1, j, n, m);
        dfsNumEnclaves(grid, visited, i, j - 1, n, m);
        dfsNumEnclaves(grid, visited, i, j + 1, n, m);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int enclaves = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (grid[i][0])
                dfsNumEnclaves(grid, visited, i, 0, n, m);
            if (grid[i][m - 1])
                dfsNumEnclaves(grid, visited, i, m - 1, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j])
                dfsNumEnclaves(grid, visited, 0, j, n, m);
            if (grid[n - 1][j])
                dfsNumEnclaves(grid, visited, n - 1, j, n, m);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] && !visited[i][j])
                    enclaves++;

        return enclaves;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int time = 0;
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    q.push({i - 1, j});
                    grid[i - 1][j] = 2;
                    fresh--;
                }
                if (i + 1 < m && grid[i + 1][j] == 1) {
                    q.push({i + 1, j});
                    grid[i + 1][j] = 2;
                    fresh--;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    q.push({i, j - 1});
                    grid[i][j - 1] = 2;
                    fresh--;
                }
                if (j + 1 < n && grid[i][j + 1] == 1) {
                    q.push({i, j + 1});
                    grid[i][j + 1] = 2;
                    fresh--;
                }
            }
            time++;
        }
        return (fresh == 0) ? time : -1;
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prevRow(m, 1e9);
        int prev;
        for (int i = 0; i < n; i++) {
            prev = 1e9;
            for (int j = 0; j < m; j++) {
                prevRow[j] = grid[i][j] + ((min(prevRow[j], prev) == 1e9)
                                               ? 0
                                               : min(prevRow[j], prev));
                prev = prevRow[j];
            }
        }
        return prev;
    }
};
class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& obstacleGrid,
               vector<vector<int>>& dp, int m, int n) {
        if (i == m - 1 && j == n - 1 && obstacleGrid[i][j] == 0)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (i + 1 < m && obstacleGrid[i + 1][j] == 0)
            ans += helper(i + 1, j, obstacleGrid, dp, m, n);
        if (j + 1 < n && obstacleGrid[i][j + 1] == 0)
            ans += helper(i, j + 1, obstacleGrid, dp, m, n);
        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size(), m = obstacleGrid.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if(obstacleGrid[0][0] == 1) return 0;
        return helper(0, 0, obstacleGrid, dp, m, n);
    }
};
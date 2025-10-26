class Solution {
public:
    int helper(int n, int curr, vector<int>&dp){
        if(n < curr) return 0;
        else if(n == curr) return 1;
        if(dp[curr] != -1) return dp[curr];
        dp[curr] = helper(n, curr + 1, dp) + helper(n, curr + 2, dp);
        return dp[curr];
    }
    int climbStairs(int n) {
        vector<int>dp(n, -1);
        return helper(n, 0, dp);
    }
};
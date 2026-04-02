class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int& a : nums)
            totalSum += a;
        if (totalSum % 2 != 0)
            return false;
        vector<vector<int>> dp(n, vector<int>(totalSum / 2 + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (nums[0] <= totalSum / 2)
            dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= totalSum / 2; target++) {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if (nums[i] <= target) {
                    take = dp[i - 1][target - nums[i]];
                }
                dp[i][target] = notTake || take;
            }
        }
        return dp[n - 1][totalSum / 2];
    }
};
class Solution {
public:
    bool helperCanPartition(vector<int>& nums, int idx, int target,
                            vector<vector<int>>& dp) {
        if (idx == 0)
            return nums[0] == target;
        if (target == 0)
            return true;
        if (dp[idx][target] != -1)
            return dp[idx][target];
        bool notTake = helperCanPartition(nums, idx - 1, target, dp);
        bool take = false;
        if (nums[idx] <= target)
            take = helperCanPartition(nums, idx - 1, target - nums[idx], dp);
        return dp[idx][target] = notTake || take;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for (int& a : nums)
            totalSum += a;
        if (totalSum % 2 != 0)
            return false;
        vector<vector<int>> dp(n, vector<int>(totalSum / 2 + 1, -1));
        return helperCanPartition(nums, n - 1, totalSum / 2, dp);
    }
};
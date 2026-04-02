class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int& a : nums)
            totalSum += a;
        if (totalSum % 2 != 0)
            return false;
        int k = totalSum / 2;
        vector<bool> dp(k + 1, false);
        dp[0] = true;
        if (nums[0] <= k)
            dp[nums[0]] = true;
        for (int i = 1; i < n; i++) {
            vector<bool> temp(k + 1, false);
            temp[0] = true;
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[target];
                bool take = false;
                if (nums[i] <= target) {
                    take = dp[target - nums[i]];
                }
                temp[target] = notTake || take;
            }
            dp = temp;
        }
        return dp[k];
    }
};
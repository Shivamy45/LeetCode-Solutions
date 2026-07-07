class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], maxSum = nums[0];
        for (int j = 1; j < nums.size(); j++) {
            if (sum + nums[j] <= nums[j])
                sum = nums[j];
            else
                sum += nums[j];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
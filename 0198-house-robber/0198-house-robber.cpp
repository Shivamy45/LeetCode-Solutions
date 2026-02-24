class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev = nums[0], curr;
        for (int i = 1; i < nums.size(); i++) {
            curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
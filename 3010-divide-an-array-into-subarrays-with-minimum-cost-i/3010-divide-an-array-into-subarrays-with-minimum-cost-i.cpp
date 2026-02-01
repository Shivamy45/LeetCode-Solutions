class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0], second = nums[1], third = nums[2];
        for (int i = 3; i < n; i++) {
            if (nums[i] < third) {
                if (second > third)
                    second = third;
                third = nums[i];
            } else if (nums[i] < second) {
                second = nums[i];
            }
        }
        return first + second + third;
    }
};
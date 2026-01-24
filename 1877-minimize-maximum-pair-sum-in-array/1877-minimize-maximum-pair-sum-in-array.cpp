class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0, i = 0, j = n - 1;
        while(i < j){
            sum = max(sum, nums[i] + nums[j]);
            i++;
            j--;
        }
        return sum;
    }
};
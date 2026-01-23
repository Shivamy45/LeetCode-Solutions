class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int minNum = nums[i], maxNum = nums[i];
            for (int j = i; j < n; j++) {
                if (minNum > nums[j])
                    minNum = nums[j];
                else if (maxNum < nums[j])
                    maxNum = nums[j];

                res += maxNum - minNum;
            }
        }
        return res;
    }
};
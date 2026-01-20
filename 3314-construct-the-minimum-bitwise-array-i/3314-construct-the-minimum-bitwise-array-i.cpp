class Solution {
public:
    int helper(int n) {
        for (int i = 1; i <= n; i++) {
            if ((i | (i + 1)) == n)
                return i;
        }
        return -1;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = helper(nums[i]);
        }
        return res;
    }
};
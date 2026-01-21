class Solution {
public:
    int helper(int n) {
        if (n == 2)
            return -1;
        int pos = 0;
        while (n > 0 && ((n >> pos) & 1))
            pos++;
        cout << pos << endl;
        return n ^ (1 << (pos - 1));
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
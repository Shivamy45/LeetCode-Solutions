class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int cnt = 0, maxIdx = 0, currMaxIdx = 0;
        for (int i = 0; i < n - 1 && maxIdx < n - 1; i++) {
            currMaxIdx = max(currMaxIdx, i + nums[i]);
            if (i == maxIdx) {
                maxIdx = max(maxIdx, currMaxIdx);
                cnt++;
            }
        }
        return cnt;
    }
};
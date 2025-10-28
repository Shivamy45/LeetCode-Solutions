class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefSum(n);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (prefSum[n - 1] - 2 * prefSum[i] == 0)
                    res += 2;
                else if (prefSum[n - 1] - 2 * prefSum[i] == 1 ||
                         prefSum[n - 1] - 2 * prefSum[i] == -1)
                    res++;
            }
        }
        return res;
    }
};
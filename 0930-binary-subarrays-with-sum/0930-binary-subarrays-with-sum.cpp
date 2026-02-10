class Solution {
public:
    int helper(vector<int>& arr, int k) {
        if (k < 0)
            return 0;
        int cnt = 0, n = arr.size();
        int i = 0, sum = 0, j = 0;
        while (j < n) {
            sum += arr[j];
            while (sum > k) {
                sum -= arr[i];
                i++;
            }

            if (sum <= k)
                cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int lessOrEqual = helper(nums, goal);
        int less = helper(nums, goal - 1);
        return lessOrEqual - less;
    }
};
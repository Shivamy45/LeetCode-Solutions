class Solution {
public:
    int helper(vector<int>& arr, int k) {
        if (k < 0)
            return 0;
        int n = arr.size();
        int i = 0, sum = 0, cnt = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[j];
            while (sum > k)
                sum -= arr[i++];

            cnt += (j - i + 1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};
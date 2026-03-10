class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long i = 0, total = 0, res = 0;
        for(long long j = 0; j < n; j++){
            total += nums[j];
            while((nums[j] * (j - i + 1)) > (total + k)) {
                total -= nums[i];
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
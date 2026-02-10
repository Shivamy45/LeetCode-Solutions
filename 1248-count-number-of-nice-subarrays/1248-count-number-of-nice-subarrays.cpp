class Solution {
public:
    int helperNumberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, oddCnt = 0, res = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] % 2 == 1)
                oddCnt++;
            while (oddCnt > k) {
                if (nums[i] % 2)
                    oddCnt--;
                i++;
            }
            res += (j - i + 1);
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helperNumberOfSubarrays(nums, k) -
               helperNumberOfSubarrays(nums, k - 1);
    }
};
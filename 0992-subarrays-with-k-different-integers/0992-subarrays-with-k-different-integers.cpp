class Solution {
public:
    int helperSubarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int cnt = 0, i = 0, dist = 0;
        for (int j = 0; j < n; j++) {
            freq[nums[j]]++;
            if (freq[nums[j]] == 1)
                dist++;
            while (dist > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    dist--;
                i++;
            }
            cnt += (j - i + 1);
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helperSubarraysWithKDistinct(nums, k) -
               helperSubarraysWithKDistinct(nums, k - 1);
    }
};
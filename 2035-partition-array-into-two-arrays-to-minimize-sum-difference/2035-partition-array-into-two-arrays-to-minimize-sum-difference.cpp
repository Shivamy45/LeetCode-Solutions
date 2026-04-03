class Solution {
public:
    void generate(int ind, int count, int currSum, int end, vector<int>& nums,
                  vector<vector<int>>& sums) {
        if (ind > end) {
            sums[count].push_back(currSum);
            return;
        }
        generate(ind + 1, count, currSum, end, nums, sums);
        generate(ind + 1, count + 1, currSum + nums[ind], end, nums, sums);
    }

    vector<vector<int>> calculateAllSubsetSum(vector<int>& nums, int start,
                                              int end) {
        int n = end - start + 1;
        vector<vector<int>> sums(n + 1);
        generate(start, 0, 0, end, nums, sums);
        return sums;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int& a : nums)
            totalSum += a;
        int m = n / 2;
        vector<vector<int>> left(m + 1), right(m + 1);
        left = calculateAllSubsetSum(nums, 0, m - 1);
        right = calculateAllSubsetSum(nums, m, n - 1);
        for (int k = 0; k <= m; k++)
            sort(right[k].begin(), right[k].end());
        int ans = 1e9;
        for (int k = 0; k <= m; k++) {
            for (int sumL : left[k]) {
                int target = totalSum / 2 - sumL;
                auto& vec = right[m - k];
                auto it = lower_bound(vec.begin(), vec.end(), target);
                if (it != vec.end()) {
                    int chosen = sumL + *it;
                    ans = min(ans, abs(totalSum - 2 * chosen));
                }
                if (it != vec.begin()) {
                    --it;
                    int chosen = sumL + *it;
                    ans = min(ans, abs(totalSum - 2 * chosen));
                }
            }
        }
        return ans;
    }
};
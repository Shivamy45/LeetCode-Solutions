class Solution {
public:
    void helperSubsetsWithDup(vector<int>& nums, int idx,
                              vector<vector<int>>& res, vector<int>& temp,
                              int n) {
        res.push_back(temp);
        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            helperSubsetsWithDup(nums, i + 1, res, temp, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        helperSubsetsWithDup(nums, 0, res, temp, nums.size());
        return res;
    }
};
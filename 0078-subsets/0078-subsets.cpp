class Solution {
public:
    void helperSubsets(vector<int>& nums, vector<vector<int>>& res,
                       vector<int>& temp, int idx) {
        if (idx == nums.size()) {
            res.push_back(temp);
            return;
        }
        helperSubsets(nums, res, temp, idx + 1);
        temp.push_back(nums[idx]);
        helperSubsets(nums, res, temp, idx + 1);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helperSubsets(nums, res, temp, 0);
        return res;
    }
};
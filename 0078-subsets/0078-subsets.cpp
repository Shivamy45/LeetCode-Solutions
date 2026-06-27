class Solution {
public:
    void helper(vector<int>& nums, int idx, vector<int>& temp,
                vector<vector<int>>& ans) {
        ans.push_back(temp);
        if (idx == nums.size()) {
            return;
        }
        for (int j = idx; j < nums.size(); j++) {

            temp.push_back(nums[j]);
            helper(nums, j + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, 0, temp, ans);
        return ans;
    }
};
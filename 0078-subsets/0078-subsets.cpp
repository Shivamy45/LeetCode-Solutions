class Solution {
public:
    void helper(vector<int>&nums, int idx, vector<int>&temp, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }
        helper(nums, idx + 1, temp, ans);
        temp.push_back(nums[idx]);
        helper(nums, idx + 1, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, 0, temp, ans);
        return ans;
    }
};
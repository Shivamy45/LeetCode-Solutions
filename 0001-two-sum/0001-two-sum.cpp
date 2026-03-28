class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            int val = target - nums[i];
            if(mpp.count(val)) return {i, mpp[val]};
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
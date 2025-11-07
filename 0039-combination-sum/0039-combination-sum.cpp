class Solution {
public:
    void helperCombinationSum(vector<int>& arr, int k, vector<vector<int>>& res,
                              int idx, vector<int>& temp) {
        if (k == 0) {
            res.push_back(temp);
            return;
        }
        if (k < 0 || idx == arr.size())
            return;
        helperCombinationSum(arr, k, res, idx + 1, temp);
        temp.push_back(arr[idx]);
        helperCombinationSum(arr, k - arr[idx], res, idx, temp);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        helperCombinationSum(candidates, target, res, 0, temp);
        return res;
    }
};
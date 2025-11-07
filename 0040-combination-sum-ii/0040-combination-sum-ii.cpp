class Solution {
public:
    void helperCombinationSum2(vector<int>& candidates, int idx, int target,
                               vector<vector<int>>& res, vector<int>& temp) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (target < 0 || idx == candidates.size())
            return;
        for (int i = idx; i < candidates.size(); i++) {
            if (i == idx || candidates[i - 1] != candidates[i]) {
                temp.push_back(candidates[i]);
                helperCombinationSum2(candidates, i + 1, target - candidates[i],
                                      res, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        helperCombinationSum2(candidates, 0, target, res, temp);
        return res;
    }
};
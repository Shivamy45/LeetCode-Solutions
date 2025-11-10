class Solution {
public:
    void helperCombinationSum3(int k, int n, vector<int>& temp,
                               vector<vector<int>>& res) {
        if (k == 0 && n == 0)
            res.push_back(temp);
        else if (k <= 0 || n <= 0)
            return;
        int start = (temp.empty()) ? 0 : temp.back();
        for (int i = start + 1; i <= 9; i++) {
            temp.push_back(i);
            helperCombinationSum3(k - 1, n - i, temp, res);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helperCombinationSum3(k, n, temp, res);
        return res;
    }
};
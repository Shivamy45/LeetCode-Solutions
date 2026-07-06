class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        for (auto interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0])
                res.push_back(interval);
            else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};
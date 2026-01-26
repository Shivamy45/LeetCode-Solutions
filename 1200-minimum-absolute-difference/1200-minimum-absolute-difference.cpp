class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int absDiff = abs(arr[1] - arr[0]);
        for (int i = 0; i < n - 1; i++)
            absDiff = min(absDiff, abs(arr[i+1] - arr[i]));
        vector<vector<int>> res;
        for (int i = 0; i < n - 1; i++) {
            if (abs(arr[i + 1] - arr[i]) == absDiff) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};
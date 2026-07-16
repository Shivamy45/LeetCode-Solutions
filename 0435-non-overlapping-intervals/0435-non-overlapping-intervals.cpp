class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        int prev = 0, cnt = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[prev][1]) {
                cnt++;
            } else
                prev = i;
        }
        return cnt;
    }
};
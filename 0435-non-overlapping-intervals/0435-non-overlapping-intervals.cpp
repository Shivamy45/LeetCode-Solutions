class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prev = 0, cnt = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[prev][1]) {
                if (intervals[i][1] < intervals[prev][1])
                    prev = i;
                cnt++;
            } else
                prev = i;
        }
        return cnt;
    }
};
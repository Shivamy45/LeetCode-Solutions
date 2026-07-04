class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int st = newInterval[0], end = newInterval[1];
        int i = 0;
        for (; i < intervals.size(); i++) {
            if (newInterval[1] < intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            } else if ((intervals[i][0] <= newInterval[0] &&
                        newInterval[0] <= intervals[i][1]) ||
                       (intervals[i][0] <= newInterval[1] &&
                        newInterval[1] <= intervals[i][1]) ||
                       (newInterval[0] <= intervals[i][0] &&
                        intervals[i][1] <= newInterval[1]) ||
                       (intervals[i][0] <= newInterval[0] &&
                        newInterval[1] <= intervals[i][1])) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin() + i);
                --i;
            }
        }
        if (i == intervals.size()) {
            intervals.push_back(newInterval);
        }
        return intervals;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int total = 1;
        int i = 1;
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                total++;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                total += peak;
                i++;
            }
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                total += down;
                down++;
                i++;
            }
            if (down > peak)
                total += (down - peak);
        }

        return total;
    }
};
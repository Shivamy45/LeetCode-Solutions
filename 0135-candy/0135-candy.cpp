class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> right(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;
            else
                right[i] = 1;
        }
        int candy = 0, given = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || ratings[i] > ratings[i - 1]) {
                given++;
            } else
                given = 1;
            candy += max(right[i], given);
        }
        return candy;
    }
};
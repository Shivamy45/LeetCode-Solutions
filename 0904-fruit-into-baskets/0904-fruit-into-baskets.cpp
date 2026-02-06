class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> freq;
        if (n == 1)
            return 1;
        int i = 0, j = 0, dist = 0, res = 0;
        while (j < n) {
            freq[fruits[j]]++;
            if (freq[fruits[j]] == 1)
                dist++;
            while (dist > 2) {
                freq[fruits[i]]--;
                if (freq[fruits[i]] == 0)
                    dist--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
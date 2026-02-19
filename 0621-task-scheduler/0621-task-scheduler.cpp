class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks)
            freq[task - 'A']++;
        int maxf = 0, k = 0;
        for (int f : freq) {
            if (f > maxf) {
                maxf = f;
                k = 1;
            } else if (f == maxf && f > 0)
                k++;
        }
        return max((int)tasks.size(), (maxf - 1) * (n + 1) + k);
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks)
            freq[c - 'A']++;

        int fmax = 0, k = 0;
        for (int f : freq) {
            if (f > fmax) {
                fmax = f;
                k = 1;
            } else if (f == fmax && f > 0) {
                k++;
            }
        }

        return max((int)tasks.size(), (fmax - 1) * (n + 1) + k);
    }
};
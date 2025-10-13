class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), sum = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            fill(freq.begin(), freq.end(), 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int minFreq = INT_MAX, maxFreq = INT_MIN;
                for (int count : freq) {
                    if (count == 0)
                        continue;
                    minFreq = min(minFreq, count);
                    maxFreq = max(maxFreq, count);
                }
                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int maxf = 0, i = 0, j = 0, res = 0;
        while (j < n) {
            freq[s[j] - 'A']++;
            maxf = max(maxf, freq[s[j] - 'A']);
            int changes = j - i + 1 - maxf;
            while (changes > k) {
                freq[s[i++] - 'A']--;
                maxf = 0;
                for (int k = 0; k < 26; k++)
                    maxf = max(maxf, freq[k]);
                changes = j - i + 1 - maxf;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0, cnt = 0;
        vector<int> freq(3, 0);
        for (int j = 0; j < n; j++) {
            freq[s[j] - 'a']++;
            while (freq[0] && freq[1] && freq[2]) {
                cnt += (n - j);
                freq[s[i] - 'a']--;
                i++;
            }
        }
        return cnt;
    }
};
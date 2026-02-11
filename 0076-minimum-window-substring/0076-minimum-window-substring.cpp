class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        unordered_map<char, int> freq;
        for (char c : t)
            freq[c]++;
        int i = 0, matched = 0;
        int start = -1, len = -1;
        for (int j = 0; j < n; j++) {
            if (freq.find(s[j]) != freq.end()) {
                freq[s[j]]--;
                if (freq[s[j]] >= 0)
                    matched++;
            }
            while (matched == m) {
                if (start == -1 || len > j - i + 1) {
                    start = i;
                    len = j - i + 1;
                }
                if (freq.find(s[i]) != freq.end()) {
                    freq[s[i]]++;
                    if (freq[s[i]] > 0)
                        matched--;
                }
                i++;
            }
        }
        return (start == -1) ? "" : s.substr(start, len);
    }
};
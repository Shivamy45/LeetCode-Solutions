class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> sett;
        int i = 0, j = 0, res = 0;
        while (j < n) {
            while (!sett.empty() && sett.find(s[j]) != sett.end())
                sett.erase(s[i++]);
            sett.insert(s[j]);
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
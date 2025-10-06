class Solution {
public:
    bool isAnagram(string s, string t) {
        int m1[26] = {0};
        int n = s.length(), m = t.length();
        if(n != m) return false;
        for (int i = 0; i < n; i++) {
            m1[s[i] - 'a']++;
            m1[t[i] - 'a']--;
        }
        for (int cnt : m1)
            if (cnt != 0)
                return false;
        return true;
    }
};
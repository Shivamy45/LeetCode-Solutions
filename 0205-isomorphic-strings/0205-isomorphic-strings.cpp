class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length(), m = t.length();
        if (n != m)
            return false;
        map<char, char> mpp, mpp2;
        for (int i = 0; i < n; i++) {
            if (mpp.find(s[i]) != mpp.end() || mpp2.find(t[i]) != mpp2.end()) {
                if (mpp[s[i]] != t[i] || mpp2[t[i]] != s[i])
                    return false;
            } else {
                mpp[s[i]] = t[i];
                mpp2[t[i]] = s[i];
            }
        }
        return true;
    }
};
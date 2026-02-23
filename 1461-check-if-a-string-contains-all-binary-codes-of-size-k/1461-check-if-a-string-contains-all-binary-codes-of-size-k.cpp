class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k >= s.length())
            return false;
        unordered_set<string> binary;
        for (int i = 0; i <= s.length() - k; i++) {
            binary.insert(s.substr(i, k));
        }
        return binary.size() == (1 << k);
    }
};
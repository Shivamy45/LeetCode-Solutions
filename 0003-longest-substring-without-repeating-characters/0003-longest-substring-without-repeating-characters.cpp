class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, r = 0, res = 0;
        set<char> sett;
        while(l < n && r < n){
            if(sett.find(s[r]) != sett.end()){
                while(s[l] != s[r]){
                    sett.erase(s[l]);
                    l++;
                }
                sett.erase(s[l]);
                l++;
            } else {
                res = max(res, r - l + 1);
                sett.insert(s[r]);
                r++;
            }
        }
        return res;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int len = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == ' ' && len == 0) continue;
            else if(s[i] == ' ' && len != 0) break;
            len++;
        }
        return len;
    }
};
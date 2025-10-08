class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string temp = "", res = "";
        bool first = true;
        int i = 0;
        while (i < n) {
            temp = "";
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;
            while(i < n && s[i] != ' ') temp += s[i++];
            res = temp + " " + res;
        }
        int m = res.length();
        return res.substr(0, m - 1);
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string temp = "", res = "";
        bool first = true;
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        while (i < n) {
            if (s[i] == ' ') {
                if (temp.length() != 0){
                    res = (first) ? temp + res : temp + " " + res;
                    first = false;
                }
                temp = "";
            } else {
                temp += s[i];
            }
            i++;
        }
        if(temp.length() != 0)
            res = (first) ? temp + res : temp + " " + res;
        return res;
    }
};
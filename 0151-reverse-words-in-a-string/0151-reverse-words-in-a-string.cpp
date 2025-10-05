class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(), i = 0;
        string res =  "";
        while(i < n){
            string s1 = "";
            while(s[i] != ' ' && i < n) s1 += s[i++];
            if(res != "")
                res = s1 + ' ' + res;
            else res = s1;
            while(s[i] == ' ' && i < n) i++;
        }
        
        return res;
    }
};
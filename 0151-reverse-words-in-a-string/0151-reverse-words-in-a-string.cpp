class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());
        int i = 0;
        string res = "";
        while (i < n) {
            string word = "";
            while (i < n && s[i] == ' ')
                i++;
            if(i == n) break;
            while (i < n && s[i] != ' ')
                word += s[i++];

            reverse(word.begin(), word.end());
            if (res.length() == 0)
                res += word;
            else
                res += ' ' + word;
            i++;
        }
        return res;
    }
};
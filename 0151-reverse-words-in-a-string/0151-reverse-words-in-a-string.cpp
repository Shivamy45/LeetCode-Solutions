class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i = 0;
        vector<string> words;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++; // skip spaces
            if (i >= n)
                break;
            int j = i;
            while (j < n && s[j] != ' ')
                j++;
            words.push_back(s.substr(i, j - i));
            i = j;
        }

        string res;
        for (int k = words.size() - 1; k >= 0; k--) {
            res += words[k];
            if (k != 0)
                res += ' ';
        }

        return res;
    }
};
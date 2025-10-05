class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int cnt = 0;
        vector<string> res;
        string s1;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') cnt++;
            else cnt--;
            s1 += s[i];
            if(cnt == 0){
                res.push_back(s1);
                s1 = "";
            }
        }
        string output;
        for(int i = 0; i < res.size(); i++){
            int m = res[i].length();
            output += res[i].substr(1, m - 2);
        }
        return output;
    }
};
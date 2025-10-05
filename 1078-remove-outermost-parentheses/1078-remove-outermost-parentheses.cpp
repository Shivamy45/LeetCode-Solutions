class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int cnt = 0;
        string output;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cnt++;
                if(cnt != 1) output.push_back(s[i]);
            }
            else{
                cnt--;
                if(cnt != 0) output.push_back(s[i]);
            }
        }
        return output;
    }
};
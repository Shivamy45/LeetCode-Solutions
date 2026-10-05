class Solution {
public:
    int scoreOfParentheses(string s) {
        int bal = 0, depth = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') depth++;
            else {
                depth--;
                if(s[i - 1] == '('){
                    bal += 1 << depth;
                }
            }
        }
        return bal;
    }
};
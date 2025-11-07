class Solution {
public:
    void helperGenerateParenthesis(int n, vector<string>& res, string& temp,
                                   int open, int close) {
        if (open + close > 2 * n)
            return;
        if (open == close && open + close == 2 * n) {
            res.push_back(temp);
            return;
        }
        if (close < open) {
            temp.push_back(')');
            helperGenerateParenthesis(n, res, temp, open, close + 1);
            temp.pop_back();
        }
        if (open < n) {

            temp.push_back('(');
            helperGenerateParenthesis(n, res, temp, open + 1, close);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        helperGenerateParenthesis(n, res, temp, 0, 0);
        return res;
    }
};
class Solution {
public:
    void helperGenerateParenthesis(int n, vector<string>& res, string& temp,
                                   int lcount, int rcount) {
        if (lcount + rcount > 2 * n)
            return;
        if (lcount == rcount && lcount + rcount == 2 * n) {
            res.push_back(temp);
            return;
        }
        if (rcount < lcount) {
            temp.push_back(')');
            helperGenerateParenthesis(n, res, temp, lcount, rcount + 1);
            temp.pop_back();
        }
        temp.push_back('(');
        helperGenerateParenthesis(n, res, temp, lcount + 1, rcount);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        helperGenerateParenthesis(n, res, temp, 0, 0);
        return res;
    }
};
class Solution {
public:
    void helperLetterCombinations(string digits, int idx, int n,
                                  vector<string>& keypad, string& temp,
                                  vector<string>& res) {
        if (idx == n) {
            res.push_back(temp);
            return;
        }
        for (char c : keypad[digits[idx] - '0']) {
            temp.push_back(c);
            helperLetterCombinations(digits, idx + 1, n, keypad, temp, res);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> keypad = {"",    "",    "abc",  "def", "ghi",
                                 "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp = "";
        int n = digits.size();
        vector<string> res;
        helperLetterCombinations(digits, 0, n, keypad, temp, res);
        return res;
    }
};
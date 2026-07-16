class Solution {
public:
    void helperAddOperators(string num, int target, int idx, long long curr,
                            int prevOperand, string temp, vector<string>& res) {
        if (idx == num.length()) {
            if (curr == target)
                res.push_back(temp);
            return;
        }
        for (int i = idx; i < num.length(); i++) {
            if (i > idx && num[idx] == '0')
                break;
            string valString = num.substr(idx, i - idx + 1);
            long long val = stoll(valString);

            if (idx == 0) {
                helperAddOperators(num, target, i + 1, val, val, valString,
                                   res);
            } else {
                helperAddOperators(num, target, i + 1, curr + val, val,
                                   temp + '+' + valString, res);
                helperAddOperators(num, target, i + 1, curr - val, -val,
                                   temp + '-' + valString, res);
                helperAddOperators(num, target, i + 1,
                                   curr - prevOperand + (prevOperand * val),
                                   prevOperand * val, temp + '*' + valString,
                                   res);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        helperAddOperators(num, target, 0, 0, 0, "", res);
        return res;
    }
};
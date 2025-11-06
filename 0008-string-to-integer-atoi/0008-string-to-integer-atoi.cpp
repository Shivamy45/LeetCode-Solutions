class Solution {
public:
    int helperMyAtoi(string s, int i, int sign, long long res) {
        if (i >= s.size() || !isdigit(s[i]))
            return (int)(sign * res);
        res = (res * 10) + (s[i] - '0');
        if (sign * res >= INT_MAX)
            return INT_MAX;
        if (sign * res <= INT_MIN)
            return INT_MIN;
        return helperMyAtoi(s, i + 1, sign, res);
    }

    int myAtoi(string s) {
        int n = s.length();
        int i = 0, sign = 1;
        while (i < n && s[i] == ' ')
            i++;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < n && s[i] == '0')
            i++;
        return helperMyAtoi(s, i, sign, 0);
    }
};
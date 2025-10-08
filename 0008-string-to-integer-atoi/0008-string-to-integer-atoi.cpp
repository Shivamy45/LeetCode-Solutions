class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int n = s.length();
        bool neg = false;
        int i = 0;
        while (s[i] == ' ' && i < n)
            i++;
        if (s[i] == '-') {
            neg = true;
            i++;
        } else if (s[i] == '+')
            i++;

        while (s[i] == '0' && i < n)
            i++;
        while (i < n && isdigit(s[i]) && res < INT_MAX && res > INT_MIN) {
            res = (res * 10) + (s[i] - '0');
            i++;
        }
        if (neg && (0 - res) < INT_MIN)
            return INT_MIN;
        if (!neg && res > INT_MAX)
            return INT_MAX;
        return (neg) ? 0 - res : res;
    }
};
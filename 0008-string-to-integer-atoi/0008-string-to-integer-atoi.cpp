class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        bool neg = false;
        long long res = 0;
        while (i < n && s[i] == ' ')
            i++;
        if (i < n && s[i] == '-') {
            i++;
            neg = true;
        } else if (i < n && s[i] == '+') {
            i++;
            neg = false;
        }
        while (i < n && s[i] == '0')
            i++;
        while (i < n && isdigit(s[i])) {
            if (!neg && res > INT_MAX)
                return INT_MAX;
            if (neg && -res < INT_MIN)
                return INT_MIN;
            res = (res * 10) + (s[i] - '0');
            i++;
        }
        if (!neg && res > INT_MAX)
            return INT_MAX;
        if (neg && -res < INT_MIN)
            return INT_MIN;
        return (neg) ? -res : res;
    }
};
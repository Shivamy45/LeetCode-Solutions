class Solution {
public:
    string largestOddNumber(string num) {
        int last = -1;
        int n = num.length(), i;
        for (i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                last = i;
                break;
            }
        }
        i = 0;
        while (num[i] == '0' && i <= last)
            i++;

        return num.substr(i, last + 1);
    }
};
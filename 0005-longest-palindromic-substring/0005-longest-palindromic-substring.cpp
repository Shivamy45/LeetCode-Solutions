class Solution {
public:
    int expandFromCenter(string s, int left, int right) {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, end = 0;
        for (int center = 0; center < n; center++) {
            int oddSize = expandFromCenter(s, center, center);
            int evenSize = expandFromCenter(s, center, center + 1);
            int res = max(evenSize, oddSize);

            if (res > end - start) {
                start = center - (res - 1) / 2;
                end = center + res / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
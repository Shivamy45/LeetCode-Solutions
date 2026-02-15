class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1, c = 0;
        string res;
        while (i >= 0 || j >= 0 || c != 0) {
            if (i >= 0)
                c += a[i] - '0';
            if (j >= 0)
                c += b[j] - '0';
            res += (c % 2) + '0';
            c /= 2;
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
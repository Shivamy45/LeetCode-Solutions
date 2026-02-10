class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0, cnt = 0, a = 0, b = 0, c = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'a')
                a++;
            else if (s[j] == 'b')
                b++;
            else if (s[j] == 'c')
                c++;

            while (a > 0 && b > 0 && c > 0) {
                if (s[i] == 'a')
                    a--;
                else if (s[i] == 'b')
                    b--;
                else if (s[i] == 'c')
                    c--;
                i++;
            }
            cnt += (j - i + 1);
        }
        long long total = (long long)n * (n + 1) / 2;
        return total - cnt;
    }
};
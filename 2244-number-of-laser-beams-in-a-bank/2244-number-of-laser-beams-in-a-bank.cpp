class Solution {
public:
    int countDevice(string s) {
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                cnt++;
        }
        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prevCnt = 0, cnt = 0, res = 0;
        for (int i = 0; i < n; i++) {
            cnt = countDevice(bank[i]);
            if (cnt > 0) {
                res += cnt * prevCnt;
                prevCnt = cnt;
            }
        }
        return res;
    }
};
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int n = columnTitle.length();
        for(int i = n - 1; i >= 0; i--){
            res += pow(26, n - i - 1) * (columnTitle[i] - 'A' + 1);
        }
        return res;
    }
};
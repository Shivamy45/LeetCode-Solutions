class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long res = 0;
        for(int i = 1; i <= n; i++){
            int noOfBits = log2(i) + 1;
            res = (res << noOfBits);
            res = res | i;
            res %= MOD;
        }
        return res;
    }
};
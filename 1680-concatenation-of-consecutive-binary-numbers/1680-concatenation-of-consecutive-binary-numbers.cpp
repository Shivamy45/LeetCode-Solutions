class Solution {
public:
    int noOfBits(int n){
        return log2(n) + 1;
    }
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long res = 0;
        for(int i = 1; i <= n; i++){
            res = ((res << noOfBits(i)) | i) % MOD;
        }
        return res;
    }
};
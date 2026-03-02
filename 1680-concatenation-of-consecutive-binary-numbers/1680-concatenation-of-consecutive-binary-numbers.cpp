class Solution {
public:
    static int concatenatedBinary(int n) {
        constexpr int MOD = 1e9 + 7;
        uint64_t res = 0;
        for(unsigned i = 1; i <= n; i++){
            const int noOfBits = 32 - countl_zero(i);
            res = ((res << noOfBits) | i) % MOD;
        }
        return res;
    }
};
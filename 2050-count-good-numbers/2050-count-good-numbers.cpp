class Solution {
public:
    const long long MOD = 1000000007;

    long long modPow(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
            if (n & 1)
                res = (res * x) % MOD;
            x = (x * x) % MOD;
            n >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        long long a = modPow(5, evenPos);
        long long b = modPow(4, oddPos);

        return (a * b) % MOD;
    }
};
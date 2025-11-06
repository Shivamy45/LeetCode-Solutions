class Solution {
public:
    const long long MOD = 1000000007;

    long long helperCountGoodNumbers(long long x, long long n) {
        if (n == 0)
            return 1;
        if (n % 2)
            return (x % MOD) * (helperCountGoodNumbers(x, n - 1) % MOD);
        else
            return helperCountGoodNumbers((x % MOD) * (x % MOD), n / 2) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        long long a = helperCountGoodNumbers(5, evenPos) % MOD;
        long long b = helperCountGoodNumbers(4, oddPos) % MOD;

        return (a * b) % MOD;
    }
};
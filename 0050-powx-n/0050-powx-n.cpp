class Solution {
public:
    double helperMyPow(double x, long long n, double res) {
        if (n == 0)
            return res;
        if (n % 2)
            return helperMyPow(x, n - 1, res * x);
        else
            return helperMyPow(x * x, n / 2, res);
        return 1.0;
    }

    double myPow(double x, int n) {
        if(x == 1) return 1;
        long long nn = (n < 0) ? (long long)-1 * n : n;
        double res = helperMyPow(x, nn, 1.0);
        if (n < 0)
            return 1.0 / res;
        return res;
    }
};
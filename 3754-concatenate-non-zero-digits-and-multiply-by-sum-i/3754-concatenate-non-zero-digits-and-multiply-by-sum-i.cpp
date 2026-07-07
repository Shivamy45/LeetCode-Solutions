class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, x = 0;
        int d = 1;
        while (n > 0) {
            int r = n % 10;
            if(r != 0){
                x = r * d + x;
                sum += r;
                d *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};
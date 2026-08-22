class Solution {
public:
    bool checkDivisibility(int n) {
        long long prod = 1, sum = 0;
        int temp = n;
        while(temp){
            int r = temp % 10;
            temp /= 10;
            prod *= r;
            sum += r;
        }
        return (n % (prod + sum) == 0);
    }
};
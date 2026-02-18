class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool x = n & 1;
        while (n > 0) {
            if ((n & 1) == x) {
                x = !x;
            } else
                return false;
            n >>= 1;
        }
        return true;
    }
};
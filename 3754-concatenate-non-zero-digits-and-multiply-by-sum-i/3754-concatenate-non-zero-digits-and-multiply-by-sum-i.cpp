class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string x = "";
        while(n > 0){
            int r = n % 10;
            if(r != 0){
                x = to_string(r) + x;
                sum += r;
            }
            n /= 10;
        }
        return x != "" ? stoi(x) * sum : 0;
    }
};
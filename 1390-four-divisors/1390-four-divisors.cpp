class Solution {
public:
    int has4divisor(int n){
        int cnt = 0, sumOfDiv = 0;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                if(i * i == n){
                    cnt++;
                    sumOfDiv += i;
                }
                else {
                    cnt += 2;
                    sumOfDiv += (i + (n / i));
                }
            }
        }
        return (cnt == 4) ? sumOfDiv : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res += has4divisor(nums[i]);
        }
        return res;
    }
};
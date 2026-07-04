class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        int lastZero = -1;
        bool canJump = true;
        for (int i = n - 1; i >= 0; i--) {
            if (lastZero == -1 && nums[i] == 0) {
                lastZero = i;
                canJump = false;
            } else if (lastZero != -1 && nums[i] < lastZero - i) {
                canJump = false;
            } else if (lastZero != -1 && nums[i] > lastZero - i) {
                lastZero = -1;
                canJump = true;
            } else if (lastZero == n - 1 && nums[i] == lastZero - i){
                lastZero = -1;
                canJump = true;
            }
        }
        return canJump;
    }
};
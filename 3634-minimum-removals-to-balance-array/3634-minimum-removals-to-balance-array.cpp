class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, res = 0;
        for(int j = 0; j < n; j++){
            while(i < j && 1LL * nums[i] * k < nums[j]){
                i++;
            }
            res = max(res, j - i + 1);
        }
        return n - res;
    }
};
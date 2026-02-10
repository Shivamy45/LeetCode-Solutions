class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        set<int> odd, even;
        int res = 0;
        for (int i = 0; i < n; i++) {
            odd = set<int>();
            even = set<int>();
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0 && even.find(nums[j]) == even.end())
                    even.insert(nums[j]);
                else if (nums[j] % 2 == 1 && odd.find(nums[j]) == odd.end())
                    odd.insert(nums[j]);
                if (even.size() == odd.size())
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
};
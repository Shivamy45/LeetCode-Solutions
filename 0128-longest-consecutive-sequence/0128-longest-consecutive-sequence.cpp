class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int ans = 0;
        for (int num : us) {
            if (!us.count(num - 1)) {
                int size = 1, val = num + 1;
                while (us.count(val)) {
                    size++;
                    val++;
                }
                ans = max(ans, size);
            }
        }

        return ans;
    }
};
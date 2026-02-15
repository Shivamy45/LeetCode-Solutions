class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd, even;
        for (int i = 0; i < n; i++) {
            if (i % 2)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
        for (int i = 0; i < even.size(); i++) {
            nums[2 * i] = even[i];
        }
        for(int i = 0; i < odd.size(); i++)
            nums[2 * i + 1] = odd[i];
        return nums;
    }
};
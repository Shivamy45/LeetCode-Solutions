class Solution {
public:
    int noOfSplit(vector<int> &nums,  int maxSum){
        int currSum = 0, splits = 1;
        for(int num : nums){
            if(currSum + num > maxSum){
                splits++;
                currSum = 0;
            }
            currSum += num;
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN, high = 0;
        for(int num : nums){
            low = max(low, num);
            high += num;
        }
        while(low <= high){
            int mid = (low + high) / 2;
            if(noOfSplit(nums, mid) > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
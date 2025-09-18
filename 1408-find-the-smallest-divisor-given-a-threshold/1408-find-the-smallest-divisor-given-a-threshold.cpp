class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long low = 1, high = INT_MAX;
        for (long long num : nums)
            high = max(high, num);

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long sumQo = 0;
            for (long long num : nums)
                sumQo += ceil((float)num / mid);
            if(sumQo <= threshold){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
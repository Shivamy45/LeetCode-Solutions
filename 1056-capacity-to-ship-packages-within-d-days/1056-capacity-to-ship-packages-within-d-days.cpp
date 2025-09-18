class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = INT_MIN, high = 0;
        for (long long weight : weights){
            low = max(low, weight);
            high += weight;
        }
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            long long currWeight = 0;
            int day = 1;
            for (long long weight : weights)
            {
                if (currWeight + weight > mid)
                {
                    day++;
                    currWeight = 0;
                }
                currWeight += weight;
            }
            if (day <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
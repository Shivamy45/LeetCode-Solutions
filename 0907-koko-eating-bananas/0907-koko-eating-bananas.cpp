class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long high = INT_MIN;
        for(long long pile : piles) high = max(high, pile);
        long long low = 1, ans = high;
        while(low <= high){
            long long mid = (low + high) / 2;
            long long timeTaken = 0;
            for (int pile : piles)
                timeTaken += (long long)ceil((double)pile / mid);
            if (timeTaken <= h){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
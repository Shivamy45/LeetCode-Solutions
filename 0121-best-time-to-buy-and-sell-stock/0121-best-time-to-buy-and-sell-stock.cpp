class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, maxVal = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            maxVal = max(maxVal, prices[i]);
            profit = max(profit, maxVal - prices[i]);
        }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, buy = INT_MAX;
        for (int price : prices) {
            buy = min(buy, price);
            profit = max(profit, price - buy);
        }
        return profit;
    }
};
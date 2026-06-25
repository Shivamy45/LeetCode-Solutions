class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> sell(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < prices[i]) {
                st.pop();
            }
            if (st.empty())
                st.push(prices[i]);
            sell[i] = st.top();
        }
        int profit =0;
        for(int i = 0; i < n; i++){
            profit = max(profit, sell[i] - prices[i]);
        }
        return profit;
    }
};
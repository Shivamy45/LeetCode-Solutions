class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int h = heights[st.top()];
                st.pop();
                int w = (st.empty() ? i : i - st.top() - 1);
                res = max(res, h * w);
            }
            st.push(i);
        }
        return res;
    }
};
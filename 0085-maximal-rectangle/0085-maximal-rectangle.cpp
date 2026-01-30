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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> hist(m);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                hist[j] = (matrix[i][j] == '0' ? 0 : hist[j] + 1);
            res = max(res, largestRectangleArea(hist));
        }
        return res;
    }
};
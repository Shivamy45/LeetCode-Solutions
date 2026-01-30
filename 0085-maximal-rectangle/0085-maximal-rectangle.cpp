class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> rightSmaller(n, n - 1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty())
                rightSmaller[i] = st.top() - 1;
            st.push(i);
        }
        st = stack<int>();
        vector<int> leftSmaller(n, 0);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty())
                leftSmaller[i] = st.top() + 1;
            st.push(i);
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res =
                max(res, ((rightSmaller[i] - leftSmaller[i] + 1) * heights[i]));
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = matrix[i][j] - '0';
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == 1)
                    arr[i][j] += arr[i - 1][j];
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, largestRectangleArea(arr[i]));
        }
        return res;
    }
};
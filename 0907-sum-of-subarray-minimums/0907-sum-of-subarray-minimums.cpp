class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7, n = arr.size();
        vector<int> prevSmallest(n, -1);
        vector<int> nextSmallest(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if (!st.empty())
                prevSmallest[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                nextSmallest[i] = st.top();
            st.push(i);
        }
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            int left =
                ((prevSmallest[i] != -1) ? (i - prevSmallest[i]) : i + 1);
            int right =
                ((nextSmallest[i] != -1) ? (nextSmallest[i] - i) : n - i);
            totalSum += ((long long)arr[i] * (long long)left * (long long)right) % MOD;
        }
        return totalSum % MOD;
    }
};
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> psee(n, -1), nse(n, -1), pgee(n, -1), nge(n, -1);
        stack<int> st;
        // calculate prev smaller or equal element(psee)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty())
                psee[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        // calculate next smaller element(nse)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty())
                nse[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        // calculate prev greater or equal element(pgee)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty())
                pgee[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        // calculate next greater element(nge)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty())
                nge[i] = st.top();
            st.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long maxNum = ((pgee[i] == -1) ? i + 1 : i - pgee[i]) *
                         ((nge[i] == -1) ? n - i : nge[i] - i);
            long long minNum = ((psee[i] == -1) ? i + 1 : i - psee[i]) *
                         ((nse[i] == -1) ? n - i : nse[i] - i);
            res += (long long)nums[i] * (maxNum - minNum);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        stack<int> st;
        unordered_map<int, int> mpp;
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            mpp[nums1[i]] = i;
        for (int i = m - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            if (mpp.find(nums2[i]) != mpp.end()) {
                if (st.empty())
                    res[mpp[nums2[i]]] = -1;
                else
                    res[mpp[nums2[i]]] = st.top();
            }
            st.push(nums2[i]);
        }
        return res;
    }
};
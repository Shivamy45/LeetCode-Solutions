class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n, -1);
        stack<int> st;
        vector<int> temp(m, -1);
        unordered_map<int,int> mpp;
        for(int i = m - 1; i >= 0; i--){
            mpp[nums2[i]] = i;
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            if(!st.empty())
                temp[i] = st.top();
            st.push(nums2[i]);
        }
        for(int i = 0; i < n; i++){
            ans[i] = temp[mpp[nums1[i]]];
        }
        return ans;
    }
};
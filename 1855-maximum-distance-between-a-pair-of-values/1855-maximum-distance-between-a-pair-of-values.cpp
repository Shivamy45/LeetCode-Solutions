class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i = 0, j = 0, n = nums1.size(), m= nums2.size();
        while(i < n && j < m){
            if(i > j) j++;
            else if(nums1[i] > nums2[j]) i++;
            else {
                ans = max(ans, j - i);
                j++;
            }
        }
        return ans;
    }
};
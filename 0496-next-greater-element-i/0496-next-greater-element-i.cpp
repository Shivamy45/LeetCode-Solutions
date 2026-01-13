class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
            mpp[nums1[i]] = i;
        for (int i = 0; i < nums2.size(); i++) {
            if (mpp.find(nums2[i]) != mpp.end()) {
                int j = i + 1;
                for (; j < nums2.size(); j++)
                    if (nums2[j] > nums2[i])
                        break;
                if (j == nums2.size())
                    res[mpp[nums2[i]]] = -1;
                else
                    res[mpp[nums2[i]]] = nums2[j];
            }
        }
        return res;
    }
};
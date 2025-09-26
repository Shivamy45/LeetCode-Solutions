class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        // ensure nums1 is smaller
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int n = n1 + n2;

        int low = 0, high = n1;
        while (low <= high) {
            int x = (low + high) / 2;
            int left = n / 2 - x;

            int l1 = (x == 0 ? INT_MIN : nums1[x - 1]);
            int r1 = (x == n1 ? INT_MAX : nums1[x]);
            int l2 = (left == 0 ? INT_MIN : nums2[left - 1]);
            int r2 = (left == n2 ? INT_MAX : nums2[left]);

            if (max(l1, l2) <= min(r1, r2))
                return (n % 2) ? min(r1, r2)
                               : (max(l1, l2) + min(r1, r2)) / 2.0;
            else if (l1 > r2)
                high = x - 1;
            else
                low = x + 1;
        }
        return -1;
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int cnt = 0;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        double ele1 = -1, ele2 = -1;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                cnt++;
                if (cnt == n / 2)
                    ele1 = nums1[i];
                if (cnt - 1 == n / 2) {
                    ele2 = nums1[i];
                    break;
                }
                i++;
            } else {
                cnt++;
                if (cnt == n / 2)
                    ele1 = nums2[j];
                if (cnt - 1 == n / 2) {
                    ele2 = nums2[j];
                    break;
                }
                j++;
            }
        }

        while (i < n1) {
            cnt++;
            if (cnt == n / 2)
                ele1 = nums1[i];
            if (cnt - 1 == n / 2) {
                ele2 = nums1[i];
                break;
            }
            i++;
        }
        while (j < n2) {
            cnt++;
            if (cnt == n / 2)
                ele1 = nums2[j];
            if (cnt - 1 == n / 2) {
                ele2 = nums2[j];
                break;
            }
            j++;
        }

        if (n % 2)
            return ele2;
        return (ele1 + ele2) / 2;
    }
};
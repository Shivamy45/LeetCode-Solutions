class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if((mid == 0 || arr[mid - 1] < arr[mid]) && (mid == n - 1 || arr[mid] > arr[mid + 1])) 
                return mid;
            else if((mid == 0) || arr[mid - 1] < arr[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};
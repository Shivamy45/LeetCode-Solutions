class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1, minVal = INT_MAX;
        if(arr.size() == 1) return arr[0];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (mid == 0 || arr[mid] < arr[mid - 1])
                minVal = min(minVal, arr[mid]);
            if (arr[low] <= arr[mid]){
                 // left sorted
                 minVal = min(minVal, arr[low]);
                 low = mid + 1;
            }
            else{
                // right sorted
                minVal = min(minVal, arr[mid]);
                high = mid - 1;
            }
        }
        return minVal;
    }
};
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1, last = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == x)
            {
                low = mid + 1;
                last = mid;
            }
            else if (arr[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        low = 0, high = arr.size() - 1;
        int first = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == x)
            {
                high = mid - 1;
                first = mid;
            }
            else if (arr[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return {first, last};
    }
};
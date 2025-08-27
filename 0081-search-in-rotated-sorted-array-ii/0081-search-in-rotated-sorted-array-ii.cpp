class Solution {
public:
    bool search(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == x)
                return true;
            while (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                if(low >= high) return false;
                low++;
                high--;
            }
            if (arr[low] <= arr[mid]) // left sorted
                if (arr[low] <= x && arr[mid] >= x)
                    high = mid - 1;
                else
                    low = mid + 1;
            else // right sorted
                if (arr[mid] <= x && arr[high] >= x)
                    low = mid + 1;
                else
                    high = mid - 1;
        }
        return false;
    }
};
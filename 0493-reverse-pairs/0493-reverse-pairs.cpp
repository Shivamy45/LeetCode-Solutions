class Solution {
public:
    void merge2(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
            {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid)
            temp.push_back(arr[left++]);
        while (right <= high)
            temp.push_back(arr[right++]);
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    int countPairs(vector<int>&arr, int low, int mid, int high){
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++)
        {
            while ((right <= high) && ((long long)arr[i] > ((long long)2 * arr[right])))
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort2(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort2(arr, low, mid);
        cnt += mergeSort2(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge2(arr, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort2(nums, 0, nums.size() - 1);
    }
};
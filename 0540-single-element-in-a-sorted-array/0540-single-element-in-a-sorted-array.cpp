class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        if(n == 1) return arr[0];
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid == 0) return arr[0];
            if(arr[mid] == arr[mid - 1]){
                if((mid + 1) % 2 == 0) low = mid + 1;
                else high = mid - 1;
            } else if(arr[mid] == arr[mid + 1]){
                if((mid + 2) % 2 == 0) low = mid + 2;
                else high = mid - 1;
            } else {
                return arr[mid];
            }
        }
        return -1;
    }
};
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        long long lowRange = 0, highRange = n - 1;
        if(n <= 1){
            return (k < arr[0]) ? k : k + 1;
        }
        while (lowRange <= highRange) {
            long long mid = lowRange + (highRange - lowRange) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                lowRange = mid + 1;
            else
                highRange = mid - 1;
        }
        return k + highRange + 1;
    }
};
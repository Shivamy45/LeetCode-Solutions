class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = 0, res = INT_MAX;
        int sum = 0;
        while(right < n){
            sum += arr[right];
            while(sum >= k){
                res = min(res, right - left + 1);
                sum -= arr[left];
                left++;
            }
            right++;
        }

        return res == INT_MAX ? 0 : res;
    }
};
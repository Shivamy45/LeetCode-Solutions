class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int res = INT_MIN, pre = 1, suff = 1;
        for(int i = 0;i < n; i++){
            pre *= arr[i];
            suff *= arr[n - i - 1];
            res = max(res, max(pre, suff));
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
        }
        return res;
    }
};
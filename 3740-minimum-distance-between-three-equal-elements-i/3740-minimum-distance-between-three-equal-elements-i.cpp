class Solution {
public:
    int minimumDistance(vector<int>& arr) {
        if(arr.size() < 3) return -1;
        int n = arr.size();
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
             for(int j = i + 1; j < n; j++){
                 for(int k = j + 1; k < n; k++){
                     if(arr[i] == arr[j] && arr[j] == arr[k]){
                         res = min(res, abs(i - j) + abs(j - k) + abs(k - i));
                     }
                 }
             }
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};
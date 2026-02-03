class Solution {
public:
    bool isTrionic(vector<int>& arr) {
        int n = arr.size();
        if(n <= 3) return false;
        int p = 0, q = n - 1;
        while(p < n - 1 && arr[p] < arr[p + 1]){
            p++;
        }
        while(q > 0 && arr[q - 1] < arr[q]){
            q--;
        }
        if(p == 0 || q == n - 1 || q - p < 1) return false;
        for(int i = p; i < q; i++){
            if(arr[i] <= arr[i + 1]) return false;
        }
        return true;
    }
};
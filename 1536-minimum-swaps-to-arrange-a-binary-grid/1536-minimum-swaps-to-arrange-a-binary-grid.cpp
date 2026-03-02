class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>mostRight(n);
        for(int i = 0; i< n; i++){
            int j = n - 1;
            while(j >= 0 && grid[i][j] == 0){
                j--;
            }
            mostRight[i] = j;
        }
        int swaps = 0;
        for(int i = 0; i < n; i++){
            if(mostRight[i] <= i) continue;
            int j = i;
            while(j < n && mostRight[j] > i) j++;
            if(j == n) return -1;
            while(j > i){
                swap(mostRight[j], mostRight[j - 1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};
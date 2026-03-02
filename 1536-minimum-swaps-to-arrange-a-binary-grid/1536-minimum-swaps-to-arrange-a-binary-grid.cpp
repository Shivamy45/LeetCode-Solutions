class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>mostRight(n);
        for(int i = 0; i< n; i++){
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 1) {
                    mostRight[i] = j;
                    break;
                }
            }
        }
        int swaps = 0;
        for(int i = 0; i < n; i++){
            if(mostRight[i] <= i) continue;
            int j = -1;
            for(int k = i + 1; k < n; k++){
                if(mostRight[k] <= i) {
                    j = k;
                    break;
                }
            }
            if(j == -1) return -1;
            while(j > i){
                swap(mostRight[j], mostRight[j - 1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};
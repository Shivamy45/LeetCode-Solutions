class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = INT_MIN, water = 0;
        vector<int> rmax(n);
        rmax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rmax[i] = max(rmax[i + 1], height[i]);
        }
        for(int i = 0; i < n - 1; i++){
            lmax = max(lmax, height[i]);
            water += min(lmax, rmax[i]) - height[i];
        }
        return water;
    }
};
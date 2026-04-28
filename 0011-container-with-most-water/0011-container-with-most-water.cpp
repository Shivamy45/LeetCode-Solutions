class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while(i < j){
            int water = (j - i) * min(height[i], height[j]);
            ans = max(ans, water);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(matrix[mid][0] <= target && target <= matrix[mid][m - 1]){
                int low2 = 0, high2 = m - 1;
                while(low2 <= high2){
                    int mid2 = (low2 + high2) / 2;
                    if(matrix[mid][mid2] == target) return true;
                    else if(matrix[mid][mid2] < target) low2 = mid2 + 1;
                    else high2 = mid2 - 1;
                }
                return false;
            }
            else if(target < matrix[mid][0]) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
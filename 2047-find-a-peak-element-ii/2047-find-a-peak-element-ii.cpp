class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (n == 0 || m == 0)
            return {-1, -1};
        int low = 0, high = n - 1;
        while (low <= high) {
            int maxEleIdx = 0;
            int mid = low + (high - low) / 2;
            for (int i = 0; i < m; i++)
                if (mat[mid][maxEleIdx] < mat[mid][i])
                    maxEleIdx = i;
            if ((mid == 0 || (mat[mid][maxEleIdx] > mat[mid - 1][maxEleIdx])) &&
                (mid == n - 1 ||
                 (mat[mid][maxEleIdx] > mat[mid + 1][maxEleIdx]))) {
                return {mid, maxEleIdx};
            } else if (mid == 0 ||
                       (mat[mid][maxEleIdx] < mat[mid + 1][maxEleIdx]))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return {-1, -1};
    }
};
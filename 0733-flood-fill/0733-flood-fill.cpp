class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size(), n = image[0].size(), same = image[sr][sc];
        if(same == color) return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                if (i - 1 >= 0 && image[i - 1][j] == same) {
                    q.push({i - 1, j});
                    image[i - 1][j] = color;
                }
                if (i + 1 < m && image[i + 1][j] == same) {
                    q.push({i + 1, j});
                    image[i + 1][j] = color;
                }
                if (j - 1 >= 0 && image[i][j - 1] == same) {
                    q.push({i, j - 1});
                    image[i][j - 1] = color;
                }
                if (j + 1 < n && image[i][j + 1] == same) {
                    q.push({i, j + 1});
                    image[i][j + 1] = color;
                }
            }
        }
        return image;
    }
};
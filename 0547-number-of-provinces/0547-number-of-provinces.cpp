class Solution {
public:
    void dfs(vector<vector<int>> mat, vector<bool>& vis, int idx) {
        for (int i = 0; i < mat[idx].size(); i++) {
            if (mat[idx][i] == 1 && !vis[i]) {
                vis[i] = true;
                dfs(mat, vis, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(isConnected, vis, i);
                ans++;
            }
        }
        return ans;
    }
};
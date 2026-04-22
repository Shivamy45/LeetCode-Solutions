class Solution {
public:
    void bfs(vector<vector<int>> mat, vector<bool>& vis, int idx) {
        queue<int> q;
        q.push(idx);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < mat.size(); i++) {
                if (mat[node][i] == 1 && !vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
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
                bfs(isConnected, vis, i);
                ans++;
            }
        }
        return ans;
    }
};
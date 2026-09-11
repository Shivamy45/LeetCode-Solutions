class Solution {
public:
    bool dfs(int idx, vector<vector<int>>& directedGraph,
             vector<int>& visited) {
        if (visited[idx] == 1)
            return false;
        if (visited[idx] == 2)
            return true;
        visited[idx] = 1;
        for (int i : directedGraph[idx]) {
            if (!dfs(i, directedGraph, visited))
                return false;
        }
        visited[idx] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> directedGraph(numCourses, vector<int>());
        for (auto it : prerequisites) {
            directedGraph[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, directedGraph, visited))
                    return false;
            }
        }
        return true;
    }
};
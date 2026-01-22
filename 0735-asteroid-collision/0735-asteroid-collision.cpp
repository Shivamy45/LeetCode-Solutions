class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (asteroids[i] < 0 && !st.empty() && st.top() > 0) {
                while (!st.empty() && st.top() > 0 &&
                       abs(asteroids[i]) > st.top())
                    st.pop();
                if (!st.empty() && st.top() > 0 &&
                    abs(asteroids[i]) == st.top())
                    st.pop();
                else if (st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
            } else {

                st.push(asteroids[i]);
            }
        }
        int m = st.size();
        vector<int> res(m);
        for (int i = m - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
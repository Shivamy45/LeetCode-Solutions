class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for (char& c : tasks)
            mpp[c]++;
        priority_queue<int> pq;
        for (auto& it : mpp)
            pq.push(it.second);
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 0; i <= n; i++) {
                if (pq.empty()) {
                    if (temp.empty())
                        break;
                    time++;
                    continue;
                }
                int x = pq.top() - 1;
                pq.pop();
                if (x != 0)
                    temp.push_back(x);
                time++;
            }
            for (int& a : temp)
                pq.push(a);
            temp.clear();
        }
        return time;
    }
};
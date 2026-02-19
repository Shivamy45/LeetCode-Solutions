class Solution {
public:
    int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> mpp;
    for (char c : tasks)
        mpp[c]++;

    priority_queue<int> pq;
    for (auto &it : mpp)
        pq.push(it.second);

    int time = 0;

    while (!pq.empty())
    {
        vector<int> temp;
        int slots = n + 1;

        while (slots-- && !pq.empty())
        {
            int x = pq.top();
            pq.pop();
            if (--x > 0)
                temp.push_back(x);
            time++;
        }

        for (int x : temp)
            pq.push(x);

        if (pq.empty())
            break;

        time += slots + 1;
    }

    return time;
}
};
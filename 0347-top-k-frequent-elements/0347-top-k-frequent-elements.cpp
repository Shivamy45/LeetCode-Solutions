class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int& num : nums)
            mpp[num]++;
        priority_queue<pair<int, int>> pq;
        for (auto& it : mpp)
            pq.push(make_pair(it.second, it.first));
        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
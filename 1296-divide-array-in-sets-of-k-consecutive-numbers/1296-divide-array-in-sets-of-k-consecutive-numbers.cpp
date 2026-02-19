class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int k) {
        int n = hand.size();
        if (n % k != 0)
            return false;
        unordered_map<int, int> freq;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int h : hand) {
            freq[h]++;
        }
        for (auto it : freq)
            pq.push(it.first);
        while (!pq.empty()) {
            int x = pq.top();
            for (int i = 0; i < k; i++) {
                if (freq.count(x + i) == 0)
                    return false;
                freq[x + i]--;
                if (freq[x + i] == 0) {
                    if ((x + i) != pq.top())
                        return false;
                    pq.pop();
                }
            }
        }
        return true;
    }
};
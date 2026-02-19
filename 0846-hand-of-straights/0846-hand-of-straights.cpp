class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if (n % k != 0)
            return false;
        unordered_map<int, int> freq;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int h : hand) {
            freq[h]++;
            pq.push(h);
        }
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if (freq.count(x) == 0)
                continue;
            for (int i = 0; i < k; i++) {
                if (freq.count(x + i) == 0)
                    return false;
                freq[x + i]--;
                if (freq[x + i] == 0)
                    freq.erase(x + i);
            }
        }
        return true;
    }
};
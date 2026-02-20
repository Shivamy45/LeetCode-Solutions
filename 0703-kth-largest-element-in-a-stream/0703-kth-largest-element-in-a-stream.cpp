class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int klargest;

public:
    KthLargest(int k, vector<int>& nums) {
        klargest = k;
        for (int score : nums) {
            if (pq.size() == k && pq.top() <= score)
                pq.pop();
            if (pq.size() < k)
                pq.push(score);
        }
    }

    int add(int val) {
        if (pq.size() == klargest && pq.top() <= val)
            pq.pop();
        if (pq.size() < klargest)
            pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
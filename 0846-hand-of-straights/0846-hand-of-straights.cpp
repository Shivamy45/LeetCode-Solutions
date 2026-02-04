class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        int n = arr.size();
        if (n % k != 0)
            return false;
        map<int, int> mpp;
        for (int &x : arr)
            mpp[x]++;
        while (!mpp.empty()) {
            int x = mpp.begin()->first;
            for (int i = 0; i < k; i++) {
                int cur = x + i;
                if (!mpp.count(cur))
                    return false;
                mpp[cur]--;
                if (mpp[cur] == 0)
                    mpp.erase(cur);
            }
        }
        return true;
    }
};
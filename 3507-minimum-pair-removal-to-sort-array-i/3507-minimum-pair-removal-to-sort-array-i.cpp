class Solution {
public:
    bool isSorted(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }
    void sumMinPair(vector<int>& arr) {
        int idx = -1;
        int sum = 1e9;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] + arr[i + 1] < sum) {
                sum = arr[i] + arr[i + 1];
                idx = i;
            }
        }
        arr[idx] += arr[idx + 1];
        arr.erase(arr.begin() + idx + 1);
    }

    int minimumPairRemoval(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        while (!isSorted(arr)) {
            sumMinPair(arr);
            cnt++;
        }
        return cnt;
    }
};
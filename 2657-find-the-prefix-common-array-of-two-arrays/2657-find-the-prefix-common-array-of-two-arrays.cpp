class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mpp, mpp2;
        int n = A.size();
        for(int i = 0; i < n; i++) mpp[A[i]] = i;
        for(int i = 0; i < n; i++) mpp2[B[i]] = i;
        vector<int>res(n, 0);
        for(int i = 0; i < n; i++){
            if(i > 0)
                res[i] = res[i - 1];
            int idx = mpp2[A[i]];
            if(idx <= i) res[i]++;
            idx = mpp[B[i]];
            if(idx < i) res[i]++;
        }
        return res;
    }
};
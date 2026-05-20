class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mpp;
        int n = A.size(), cnt = 0;
        vector<int>res(n, 0);
        for(int i = 0; i < n; i++){
            if(mpp.count(A[i])) cnt++;
            else mpp[A[i]] = 1;
            if(mpp.count(B[i])) cnt++;
            else mpp[B[i]] = 1;
            res[i] = cnt;
        }
        return res;
    }
};
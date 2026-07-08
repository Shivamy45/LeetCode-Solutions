class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> ans;
        vector<long long> preSum(n + 1, 0);
        vector<long long> preNum(n + 1, 0);
        vector<long long> pow10(n + 1, 1);
        vector<int> prefCnt(n + 1, 0);
        for(int i = 0; i < n; i++){
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }
        for(int i = 0; i < n; i++){
            int c = s[i] - '0';
            prefCnt[i + 1] = prefCnt[i] + (c != 0);
            preNum[i + 1] = (c == 0) ? preNum[i] : (preNum[i] * 10 + c) % MOD;
            preSum[i + 1] = (preSum[i] + c) % MOD;
        }
        for(auto query : queries){
            int l = query[0], r = query[1];
            int sum = preSum[r + 1] - preSum[l];
            int len = prefCnt[r + 1] - prefCnt[l];
            long long num = (preNum[r + 1] - (preNum[l] * pow10[len]) % MOD + MOD) % MOD;
            ans.push_back((sum * num) % MOD);
        }
        return ans;
    }
};
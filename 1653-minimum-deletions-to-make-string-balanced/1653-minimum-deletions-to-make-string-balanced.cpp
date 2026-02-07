class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> aS(n, 0);
        vector<int> bS(n, 0);
        for(int i = 1; i < n; i++){
            bS[i] = bS[i - 1] + ((s[i - 1] == 'b') ? 1 : 0);
        }
        for(int i = n - 2; i >= 0; i--){
            aS[i] = aS[i + 1] + ((s[i + 1] == 'a') ? 1 : 0);
        }
        int res = 1e9;
        for(int i = 0; i < n; i++){
            res = min(res, aS[i] + bS[i]);
        }
        return res;
    }
};
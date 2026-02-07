class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> aS(n, 0);
        int bS = 0;
        for(int i = n - 2; i >= 0; i--){
            aS[i] = aS[i + 1] + ((s[i + 1] == 'a') ? 1 : 0);
        }
        int res = aS[0];
        for(int i = 0; i < n; i++){
            if(i > 0 && s[i-1] == 'b') bS++; 
            res = min(res, aS[i] + bS);
        }
        return res;
    }
};
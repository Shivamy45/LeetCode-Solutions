class Solution {
public:
    int minOperations(string s) {
        bool one = true;
        int cnt = 0, cnt2 = 0;
        for(int i = 0; i < s.length(); i++){
            if(one && s[i] == '0') cnt++;
            else if(!one && s[i] == '1') cnt++;
            one = !one;
        }
        one = false;
        for(int i = 0; i < s.length(); i++){
            if(one && s[i] == '0') cnt2++;
            else if(!one && s[i] == '1') cnt2++;
            one = !one;
        }
        return min(cnt, cnt2);
    }
};
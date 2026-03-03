class Solution {
public:
    string inverseAndReverseBit(string s){
        for(char &c : s){
            c = (c == '1') ? '0' : '1';
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string createBit(int n){
        if(n == 1) return "0";
        string prev = createBit(n - 1);
        return prev + "1" + inverseAndReverseBit(prev);
    }
    char findKthBit(int n, int k) {
        string bit = createBit(n);
        return bit[k - 1];
    }
};
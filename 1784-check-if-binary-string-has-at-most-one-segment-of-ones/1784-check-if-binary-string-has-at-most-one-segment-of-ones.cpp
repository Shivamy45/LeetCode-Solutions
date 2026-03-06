class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ones = true;
        for(char &c : s){
            if(c == '0') {
                ones = false;
            } else if(!ones) return false;
        }
        return true;
    }
};
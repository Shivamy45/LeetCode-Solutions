class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        for(char c : moves){
            if(c == 'U') i--;
            else if(c == 'D') i++;
            else if(c == 'R') j++;
            else if(c == 'L') j--;
        }
        return i == 0 && j == 0;
    }
};
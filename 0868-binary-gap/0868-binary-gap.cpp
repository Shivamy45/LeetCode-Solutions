class Solution {
public:
    int binaryGap(int n) {
        int dist = 0, prev = -1, cnt = 0;
        while(n > 0){
            if(n & 1){
                if(prev == -1) prev = cnt;
                else {
                    dist = max(dist, cnt - prev);
                    prev = cnt;
                }
            }
            n >>= 1;
            cnt++;
        }
        return dist;
    }
};
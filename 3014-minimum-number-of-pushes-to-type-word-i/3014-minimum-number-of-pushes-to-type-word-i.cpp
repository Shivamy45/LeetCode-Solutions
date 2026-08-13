class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int blocks = n / 8;
        // press keys in blocks of 8 at increasing presses + rem keys to press
        int ans = ((blocks * (blocks + 1) * 4) + ((n % 8) * (blocks + 1)));
        return ans;
    }
};
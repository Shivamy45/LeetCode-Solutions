class Solution {
public:
    int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    vector<int> freq(128, 0);
    int i = 0, j = 0, res = 0;
    while (j < n)
    {
        while (freq[s[j]] != 0)
            freq[s[i++]]--;
        freq[s[j]]++;
        res = max(res, j - i + 1);
        j++;
    }
    return res;
}

};
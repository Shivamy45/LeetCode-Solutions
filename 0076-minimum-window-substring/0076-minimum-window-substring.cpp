class Solution {
public:
    string minWindow(string s, string t)
{
    int n = s.length(), m = t.length();
    if(n < m)
        return "";
    vector<int> freq(128, 0);
    for (char c : t)
        freq[c]++;
    int i = 0, matched = 0;
    int start = 0, len = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (freq[s[j]] > 0)
            matched++;
        freq[s[j]]--;
        while (matched == m)
        {
            if (j - i + 1 < len)
            {
                start = i;
                len = j - i + 1;
            }
            freq[s[i]]++;
            if (freq[s[i]] > 0)
                matched--;
            i++;
        }
    }
    return (len == INT_MAX) ? "" : s.substr(start, len);
}
};
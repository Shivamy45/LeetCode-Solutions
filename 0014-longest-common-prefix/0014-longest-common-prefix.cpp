class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[n - 1];
        int cnt = 0;
        for (int i = 0; i < first.length(); i++) {
            if (first[i] != last[i])
                break;
            cnt++;
        }
        return first.substr(0, cnt);
    }
};
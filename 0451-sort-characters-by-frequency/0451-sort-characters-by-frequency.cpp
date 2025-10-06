class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> freq(256);

        for (auto& c : s) {
            int fr = freq[c].second;
            freq[c] = {c, fr + 1};
        }

        sort(freq.begin(), freq.end(),
             [](auto& a, auto& b) { return a.second > b.second; });

        string res = "";

        for (int i = 0; i < 256; i++) {
            if (freq[i].second > 0) {
                char t = freq[i].first;
                int f = freq[i].second;
                string temp = string(f, t);
                res += temp;
            }
        }
        return res;
    }
};
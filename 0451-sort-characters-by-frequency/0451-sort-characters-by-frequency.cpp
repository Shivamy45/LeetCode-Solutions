class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> vec(256);

        for (auto& c : s) {
            int fr = vec[c].second;
            vec[c] = {c, fr + 1};
        }

        sort(vec.begin(), vec.end(),
             [](auto& a, auto& b) { return a.second > b.second; });

        string res;
        for (auto& it : vec) {
            res += string(it.second, it.first);
        }
        return res;
    }
};
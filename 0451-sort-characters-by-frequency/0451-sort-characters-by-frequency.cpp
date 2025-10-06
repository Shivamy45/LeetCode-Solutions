class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        for (char c : s)
            mpp[c]++;
        vector<pair<char, int>> vec(mpp.begin(), mpp.end());

        sort(vec.begin(), vec.end(),
             [](auto& a, auto& b) { return a.second > b.second; });

        string res;
        for (auto& it : vec) {
            res += string(it.second, it.first);
        }
        return res;
    }
};
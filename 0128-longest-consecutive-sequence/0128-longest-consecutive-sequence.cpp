class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sett;
        for(int num : nums) sett.insert(num);
        int ans = 0;
        for(auto it = sett.begin(); it != sett.end(); it++){
            int num = *it;
            if(sett.contains(num - 1)) continue;
            int cnt = 1;
            while(sett.contains(num + 1)){
                cnt++;
                num++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
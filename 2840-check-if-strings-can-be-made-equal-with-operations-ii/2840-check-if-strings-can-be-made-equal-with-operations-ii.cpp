class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        vector<int> even1(26, 0), odd1(26, 0), even2(26, 0), odd2(26, 0);
        for(int i = 0; i < n; i++){
            if(i % 2){
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            } else {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            }
        }
        return even1 == even2 && odd1 == odd2;
    }
};
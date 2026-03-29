class Solution {
public:
    bool helper(string &s1, string &s2, int i){
        if(s1 == s2) return true;
        if(i == 2) return false;
        bool flag = false;
        flag = flag || helper(s1, s2, i + 1);
        swap(s1[i], s1[i + 2]);
        flag = flag || helper(s1, s2, i + 1);
        return flag;
    }
    bool canBeEqual(string s1, string s2) {
        return helper(s1, s2, 0);
    }
};
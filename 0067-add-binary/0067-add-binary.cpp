class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        int i = n - 1, j = m - 1, c= 0;
        string res  = "";
        while(i >= 0 || j >= 0 || c != 0){
            int an = (i >= 0) ? a[i] - '0' : 0;
            int bn = (j >= 0) ? b[j] - '0' : 0;
            res += to_string((an + bn + c) % 2);
            if(an + bn + c >= 2){
                c = 1;
            } else {
                c = 0;
            }
            i--; j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
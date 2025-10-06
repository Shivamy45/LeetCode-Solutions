class Solution {
public:
    typedef pair<char,int>p;
    string frequencySort(string s) {
        string ans = "";
        vector<p> freq(256);
        
        for(auto &c : s){
            int fr = freq[c].second;
            freq[c] = {c,fr+1};
        }

        auto lamda = [&](p &p1,p &p2){
            return p1.second>p2.second;
        };

        sort(freq.begin(),freq.end(),lamda);

        for(int i = 0;i<256;i++){
            if(freq[i].second > 0){
            char t = freq[i].first;
            int f = freq[i].second;
            string temp = string(f,t);
            ans += temp;
            }
          
        }

        return ans;
    }
};
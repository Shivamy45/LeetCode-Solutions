class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = ' ';
        for(int i = 0;i < letters.size(); i++){
            if(letters[i] > target && (ans == ' ' || letters[i] < ans))
                ans = letters[i];
        }
        return ans == ' ' ? letters[0] : ans;
    }
};
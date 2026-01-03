class Solution {
public:
    int repeatedNTimes(vector<int>& arr) {
        for(int i = 1; i < arr.size(); i++){
            if((i > 0 && arr[i] == arr[i - 1]) || (i > 1 && arr[i] == arr[i - 2]) || (i > 2 && arr[i] == arr[i - 3])) return arr[i];
        }
        return -1;
    }
};
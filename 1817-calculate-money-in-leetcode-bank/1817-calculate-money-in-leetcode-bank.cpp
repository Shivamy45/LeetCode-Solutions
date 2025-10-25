class Solution {
public:
    int totalMoney(int n) {
        int onMon = 1, money = 0, curr = 1;
        for(int i = 0; i < n; i++){
            if(i % 7 == 0){
                curr = onMon;
                onMon++;
            } else {
                curr++;
            }
            money += curr;
        }
        return money;
    }
};
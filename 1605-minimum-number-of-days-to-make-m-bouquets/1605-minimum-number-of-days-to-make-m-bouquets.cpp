class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if (val > n) return -1;
        int low = INT_MAX, high = INT_MIN;
        for (int flowers : bloomDay)
        {
            low = min(low, flowers);
            high = max(high, flowers);
        }
        while(low <= high){
            int mid = (low + high) / 2;
            int cont = 0, bouquetMade = 0;
            for (int flowerBloom : bloomDay)
            {
                if(flowerBloom <= mid)
                    cont++;
                else
                    cont = 0;
                if (cont == k){
                    cont = 0;
                    bouquetMade++;
                }
                if(bouquetMade == m)
                    break;
            }
            if(bouquetMade >= m){
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};
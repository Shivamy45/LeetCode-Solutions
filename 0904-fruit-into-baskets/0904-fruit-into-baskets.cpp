class Solution {
public:
    int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    if (n == 1)
        return 1;
    int a = -1, b = -1, bStreak = 0, res = 0, currStreak = 0;
    for (int fruit : fruits)
    {
        if (fruit == a || fruit == b)
            currStreak++;
        else
            currStreak = bStreak + 1;
        if (fruit == b)
            bStreak++;
        else
        {
            bStreak = 1;
            a = b;
            b = fruit;
        }
        res = max(res, currStreak);
    }
    return res;
}

};
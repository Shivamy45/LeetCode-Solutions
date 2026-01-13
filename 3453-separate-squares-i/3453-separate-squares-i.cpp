class Solution {
public:
    double calcArea(vector<vector<int>>& squares, double y) {
        double area = 0;
        for (auto& s : squares) {
            double y0 = s[1] + s[2];
            if (y < y0) {
                double l = min(y0 - y, (double)s[2]);
                double b = s[2];
                area += (l * b);
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX, high = INT_MIN;
        for (auto& s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }
        double totalArea = calcArea(squares, -1e9);
        while (high - low >= 1e-5) {
            double y = (low + high) / 2;
            double aboveArea = calcArea(squares, y);
            if (aboveArea > totalArea / 2) {
                low = y;
            } else {
                high = y;
            }
        }
        return low;
    }
};
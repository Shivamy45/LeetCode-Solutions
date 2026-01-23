class Solution {
public:
    using ll = long long;

    int minimumPairRemoval(vector<int>& v) {
        int n = v.size();
        if (n <= 1)
            return 0;

        vector<ll> a(v.begin(), v.end());
        vector<int> l(n), r(n);
        vector<char> dead(n, 0);

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> h;

        int ok = 0;
        for (int i = 0; i < n; i++) {
            l[i] = i - 1;
            r[i] = i + 1;
            if (i > 0) {
                h.push({a[i - 1] + a[i], i - 1});
                if (a[i] >= a[i - 1])
                    ok++;
            }
        }

        if (ok == n - 1)
            return 0;

        int rem = n;

        while (rem > 1) {
            auto [s, i] = h.top();
            h.pop();
            int j = r[i];
            if (j >= n || dead[i] || dead[j])
                continue;
            if (a[i] + a[j] != s)
                continue;

            int x = l[i], y = r[j];

            if (a[i] <= a[j])
                ok--;
            if (x != -1 && a[x] <= a[i])
                ok--;
            if (y != n && a[j] <= a[y])
                ok--;

            a[i] += a[j];
            dead[j] = 1;
            rem--;

            l[i] = x;
            if (x != -1) {
                r[x] = i;
                h.push({a[x] + a[i], x});
                if (a[x] <= a[i])
                    ok++;
            }

            r[i] = y;
            if (y != n) {
                l[y] = i;
                h.push({a[i] + a[y], i});
                if (a[i] <= a[y])
                    ok++;
            }

            if (ok == rem - 1)
                return n - rem;
        }

        return n;
    }
};
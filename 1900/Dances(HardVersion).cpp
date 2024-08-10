#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n - 1), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    a.insert(a.begin(), 1);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (b.back() == 1) {
        cout << n * m << nl;
        return;
    }

    auto check = [&](int k) -> bool {
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                cnt++;
            }

        v<int> c, d;
        for (int i = 0; i < n - k; i++)
            c.push_back(a[i]);
        for (int i = k; i < n; i++)
            d.push_back(b[i]);

        for (int i = cnt; i; i--)
            swap(a[i], a[i - 1]);

        for (int i = 0; i < (int) c.size(); i++)
            if (c[i] >= d[i])
                return 0;
        return 1;
    };

    int ops = n;
    {
        int lo = 0, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(mid))
                ops = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
    }

    int lb = 1e9 + 1;
    {
        int lo = 1, hi = 1e9 + 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            a[0] = mid;

            int lo1 = 0, hi1 = n, ops1 = n;
            while (lo1 <= hi1) {
                int mid1 = (lo1 + hi1) / 2;

                if (check(mid1))
                    ops1 = mid1, hi1 = mid1 - 1;
                else
                    lo1 = mid1 + 1;
            }

            if (ops1 > ops)
                lb = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
    }
    cout << ops * min(lb - 1, m) + (ops + 1) * max(0ll, m - lb + 1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
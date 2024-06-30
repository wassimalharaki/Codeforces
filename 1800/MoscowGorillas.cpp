#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

int get(array<int, 2>& l, array<int, 2>& r) {
    array<int, 2> i{max(l[0], r[0]), min(l[1], r[1])};
    return max(0ll, i[1] - i[0] + 1);
}

bool belong(int x, array<int, 2> y) {
    return y[0] <= x and x <= y[1];
}

void solve() {
    int n; cin >> n;

    v<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = i;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[x] = i;
    }

    int ans = 1;
    {
        v<array<int, 2>> a1{
            {0ll, a[1] - 1},
            {a[1] + 1, n - 1}
        };
        v<array<int, 2>> b1{
            {0ll, b[1] - 1},
            {b[1] + 1, n - 1}
        };

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                int x = get(a1[i], b1[j]);
                ans += x * (x + 1) / 2;
            }
    }

    array<int, 2> y{min(a[1], b[1]), max(a[1], b[1])};
    for (int i = 2; i <= n; i++) {
        if (not belong(a[i], y) and not belong(b[i], y)) {
            int r;
            if (belong(a[i], {y[1], n - 1}) and belong(b[i], {y[1], n - 1}))
                r = min(a[i] - 1, b[i] - 1);
            else if (belong(a[i], {y[1], n - 1}))
                r = a[i] - 1;
            else if (belong(b[i], {y[1], n - 1}))
                r = b[i] - 1;
            else
                r = n - 1;
            
            int l;
            if (belong(a[i], {0, y[0]}) and belong(b[i], {0, y[0]}))
                l = max(a[i] + 1, b[i] + 1);
            else if (belong(a[i], {0, y[0]}))
                l = a[i] + 1;
            else if (belong(b[i], {0, y[0]}))
                l = b[i] + 1;
            else
                l = 0;
            ans += (r - y[1] + 1) * (y[0] - l + 1);
        }
        y[0] = min({y[0], a[i], b[i]});
        y[1] = max({y[1], a[i], b[i]});
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
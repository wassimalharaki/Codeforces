#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    for (auto& x : a)
        cin >> x[0] >> x[1] >> x[1] >> x[1];
    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        if (l[0] == r[0])
            return l[1] > r[1];
        return l[0] < r[0];
    });

    v<array<int, 2>> b{a[0]};
    for (int i = 1; i < n; i++)
        if (a[i][0] <= b.back()[1])
            b.back()[1] = max(b.back()[1], a[i][1]);
        else
            b.push_back(a[i]);

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;

        auto it = upper_bound(b.begin(), b.end(), array<int, 2>{x, (int) 1e9});
        if (it == b.begin())
            cout << x << " ";
        else
            cout << max(x, (*--it)[1]) << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
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

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 2>> one, zero;
    for (int i = 0; i < m; i++) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1)
            one.push_back({l, r});
        else
            zero.push_back({l, r});
    }
    sort(one.begin(), one.end());

    if (one.size() == 0) {
        cout << "YES" << nl;
        for (int i = 0; i < n; i++)
            cout << n - i << " ";
        return;
    }

    v<array<int, 2>> fixed{one[0]};
    for (int i = 1; i < one.size(); i++)
        if (one[i][0] <= fixed.back()[1])
            fixed.back()[1] = max(fixed.back()[1], one[i][1]);
        else
            fixed.push_back(one[i]);
    one.swap(fixed);
    
    int x = 1e8;
    v<int> a(n);
    for (auto& [l, r] : one) {
        for (int i = l - 1; i < r; i++)
            a[i] = x;
        x -= 1e4;
    }

    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            a[i] = (i ? a[i - 1] - 1 : 1e9);
    
    for (auto& [l, r] : zero) {
        bool ok = 0;
        for (int i = l - 1; i < r - 1; i++)
            ok |= a[i] > a[i + 1];
        if (not ok) {
            cout << "NO";
            return;
        }
    }
    cout << "YES" << nl;
    for (int& x : a)
        cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
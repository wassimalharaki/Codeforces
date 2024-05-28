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

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> fix{a[0]}, ind(n);
    for (int i = 1; i < n; i++) {
        if (a[i] != fix.back())
            fix.push_back(a[i]);
        ind[i] = fix.size() - 1;
    }
    a.swap(fix);

    n = a.size();
    v<int> down, up;
    for (int i = 1; i < n - 1; i++)
        if (a[i - 1] > a[i] and a[i] < a[i + 1])
            down.push_back(i);
    
    while (m--) {
        int l, r; cin >> l >> r;
        l = ind[l - 1]; r = ind[r - 1];
        if (down.empty())
            cout << "Yes" << nl;
        else {
            auto it_l = upper_bound(down.begin(), down.end(), l);
            auto it_r = lower_bound(down.begin(), down.end(), r);
            cout << (it_r - it_l > 0 ? "No" : "Yes") << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
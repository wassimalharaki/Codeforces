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

    v<int> a(m);
    for (int& x : a) cin >> x;

    if (accumulate(a.begin(), a.end(), 0ll) < n) {
        cout << -1;
        return;
    }

    int x = n;
    v<int> ans(m);
    for (int i = 0; i < m; i++)
        ans[i] = x-- - a[i] + 1;
    x = 1;
    
    if (*min_element(ans.begin(), ans.end()) <= 0) {
        cout << -1;
        return;
    }

    int ok = 0;
    for (int i = m - 1; i >= 0 and not ok; i--)
        if (ans[i] <= x)
            ok = 1;
        else
            ans[i] = x, x += a[i];
    
    if (not ok)
        cout << -1;
    else
        for (int& x : ans)
            cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
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

    v<array<int, 2>> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};
    sort(b.begin(), b.end());

    v<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[b[i][1]] = i;
    
    v<int> prefix(n + 1);
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + b[i][0];
    
    int ans = (a[0] <= m or b[0][0] <= m ? n : n + 1);
    for (int k = n - 1; k >= 1; k--) {
        int i = n - k, need = a[i] + prefix[i - 1];
        if (pos[i] + 2 <= i) need += b[i - 1][0] - a[i];
        need = min(need, prefix[i + 1]);
        if (need <= m) ans = k;
    }

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
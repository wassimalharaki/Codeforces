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
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    v<array<int, 2>> r(n);
    for (int i = 0; i < n; i++)
        r[i] = {a[i] - b[i] + 1, a[i]};
    sort(r.begin(), r.end());

    v<array<int, 2>> comb{{r[0][0], r[0][1]}};
    for (int i = 1; i < n; i++)
        if (r[i][0] <= comb.back()[1])
            comb.back()[1] = max(comb.back()[1], r[i][1]);
        else
            comb.push_back(r[i]);
    
    int ans = 0;
    for (int i = 0; i < comb.size(); i++) {
        int m = comb[i][1] - comb[i][0] + 1;   
        ans += (1 + m) * m / 2;
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
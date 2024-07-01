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

bool intersect(array<int, 2>& x, array<int, 2>& y) {
    sort(y.begin(), y.end());
    bool b = y[0] <= x[0] and x[0] <= y[1];
    bool a = y[0] <= x[1] and x[1] <= y[1];
    return a ^ b;
}

void solve() {
    int n, k; cin >> n >> k;

    v<array<int, 2>> a(k);
    v<int> b(2 * n);
    iota(b.begin(), b.end(), 1ll);
    for (auto& x : a) {
        cin >> x[0] >> x[1];
        b.erase(find(b.begin(), b.end(), x[0]));
        b.erase(find(b.begin(), b.end(), x[1]));
    }

    for (int i = 0; i < b.size() / 2; i++)
        a.push_back({b[i], b[b.size() / 2 + i]});
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += intersect(a[i], a[j]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
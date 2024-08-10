#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> r(m, 1e9);
    int x = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        r[i % m] = min(r[i % m], x - i / m * k);
        x += a[i];
        for (int j = 0; j <= i % m; j++)
            ans = max(ans, x - i / m * k - r[j] - k);
        for (int j = i % m + 1; j < m; j++)
            ans = max(ans, x - i / m * k - r[j]);
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
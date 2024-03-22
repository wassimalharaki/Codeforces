#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

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

    int add = 0;
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            add += b[i] == 0;
        else {
            int g = __gcd(b[i], a[i]);
            cnt[{-b[i] / g, a[i] / g}]++;
        }

    int ans = 0;
    for (auto& [key, val] : cnt)
        ans = max(ans, val);
    cout << ans + add << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
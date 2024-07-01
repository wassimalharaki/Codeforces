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
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    if (binary_search(a.begin(), a.end(), k)) {
        cout << "YES" << nl;
        return;
    }

    int g = 0;
    for (int i = 0; i < n - 1; i++)
        g = gcd(g, a[i + 1] - a[i]);
    cout << ((k - a[0]) % g == 0 ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
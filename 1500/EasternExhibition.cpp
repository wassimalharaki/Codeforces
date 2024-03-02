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

    v<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    sort(all(x)); sort(all(y));
    int a = x[n >> 1] - x[n - 1 >> 1] + 1;
    int b = y[n >> 1] - y[n - 1 >> 1] + 1;
    cout << a * b << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
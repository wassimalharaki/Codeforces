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

const int N = 50;
const int mod = 1e9 + 7;
v<int> ok(N);

void solve() {
    int n; cin >> n;
    int ans = 2 * n;
    for (int i = 2; i < N; i++) {
        int x = n / ok[i];
        ans += x;
    }
    cout << ans % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ok[1] = 1;
    for (int i = 2; i < N; i++)
        ok[i] = lcm(i, ok[i - 1]);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
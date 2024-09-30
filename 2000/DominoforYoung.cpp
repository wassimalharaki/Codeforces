#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    int ans = 0, e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans += x >> 1;
        if (x & 1)
            i & 1 ? o++ : e++;
    }
    cout << ans + min(e, o) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
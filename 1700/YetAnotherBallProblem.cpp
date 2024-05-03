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
 
    if (k * (k - 1) < n) {
        cout << "NO" << nl;
        return;
    }
 
    cout << "YES" << nl;
    int cnt = 0;
    for (int i = 1; i <= k; i++)
        for (int j = i + 1; j <= k; j++) {
            if (j == i) continue;
            cout << i << " " << j << nl;
            cnt++;
            if (cnt == n) return;
            cout << j << " " << i << nl;
            cnt++;
            if (cnt == n) return;
        }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
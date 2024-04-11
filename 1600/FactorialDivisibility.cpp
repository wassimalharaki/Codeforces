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
    int n, x; cin >> n >> x;

    v<int> have(x + 1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        have[a]++;
    }
    for (int i = 0; i < x; i++) {
        if (have[i] % (i + 1)) {
            cout << "No" << nl;
            return;
        }
        have[i + 1] += have[i] / (i + 1);
    }
    cout << "Yes" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
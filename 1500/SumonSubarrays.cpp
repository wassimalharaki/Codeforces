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
    int n, k; cin >> n >> k;

    int x = 1;
    for (int i = 0; i < n; i++) {
        if (k - x >= 0) {
            k -= x++;
            cout << 5 << " ";
        }
        else {
            x--;
            cout << -5 * (x - k + 1) + 1 << " ";
            i++;
            for (; i < n; i++)
                cout << -1000 << " ";
            cout << nl;
            break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
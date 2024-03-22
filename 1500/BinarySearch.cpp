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

const int mod = 1e9 + 7;

void solve() {
    int n, x, p; cin >> n >> x >> p;

    int le = x - 1, g = n - x;
    int l = 0, r = n;
    int ans = 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (p == mid) {
            l = mid + 1;
        }
        else if (p >= mid) {
            ans = ans * le-- % mod;
            l = mid + 1;
        }
        else {
            ans = ans * g-- % mod;
            r = mid;
        }
    }
    int prod = 1;
    for (int i = 2; i <= le + g; i++)
        prod = prod * i % mod;
    cout << ans * prod % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
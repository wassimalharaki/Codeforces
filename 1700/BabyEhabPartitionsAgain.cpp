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

const int N = 2e5 + 1;
bitset<N> dp;

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    int sum = accumulate(a.begin(), a.end(), 0ll);

    dp[0] = 1;
    for (int& x : a)
        dp |= dp << x;

    if ((sum & 1) or not dp[sum / 2])
        cout << 0 << nl;
    else {
        for (int i = 0; i < n; i++) {
            dp.reset();
            dp[0] = 1;
            sum -= a[i];
            for (int j = 0; j < n; j++)
                if (j != i)
                    dp |= dp << a[j];

            if ((sum & 1) or not dp[sum / 2]) {
                cout << 1 << nl << i + 1 << nl;
                break;
            }
            sum += a[i];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
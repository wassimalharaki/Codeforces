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

    int max = -INT_MAX;
    v<int> bits(32);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        max = std::max(max, a);
        int b = max - a;
        for (int j = 0; j < 32; j++)
            if ((1ll << j) & b)
                bits[j]++;
    }

    int ans = 0;
    for (int i = 0; i < 32; i++)
        if (bits[i])
            ans = i + 1;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
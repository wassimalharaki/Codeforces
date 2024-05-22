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

    if (k == 1) {
        map<int, int> one;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            ++one[x];
        }
        int ans = 0;
        for (auto& [key, val] : one)
            ans += val * (val - 1) * (val - 2) / 6;
        cout << ans;
    }
    else {
        int ans = 0;
        map<int, int> one;
        map<array<int, 2>, int> two;
        v<int> a(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = x;
            ++one[x];
            if (x == 0) continue;
            if (x % k == 0)
                two[{x, x / k}] += one[x / k];
            if (x % (k * k) == 0)
                ans += two[{x / k, x / k / k}];
        }
        int z = one[0];
        ans += z * (z - 1) * (z - 2) / 6;
        cout << ans;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
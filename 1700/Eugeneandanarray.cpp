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
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> prefix(n + 1);
    map<int, v<int>> at{{0, {-1}}};
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
        at[prefix[i + 1]].push_back(i);
    }

    int l = 0, r = 0, ans = 0;
    while (r < n) {
        auto& b = at[prefix[r + 1]];
        auto it = lower_bound(b.begin(), b.end(), r);
        if (it != b.begin()) {
            --it;
            l = max(l, *it + 2);
        }
        ans += r++ - l + 1;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
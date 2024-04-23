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
    int n, m, d; cin >> n >> m >> d;

    set<array<int, 2>> have;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        have.insert({a, i});
    }

    v<int> ans(n);
    int x = 0;
    while (have.size() and ++x) {
        auto it = have.begin();
        while (it != have.end()) {
            auto a = *it;
            ans[a[1]] = x;
            have.erase(it);
            it = have.upper_bound({a[0] + d, (int) 1e9});
        }
    }

    cout << x << nl;
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

template<typename T>
using ordered_set = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    ordered_set<pair<int, int>> l, r;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        l.insert({a[i][0], i});
        r.insert({a[i][1], i});
    }
    r.insert({1e9, 1e9});
    l.insert({1e9, 1e9});

    int ans = n;
    for (int i = 0; i < n; i++) {
        int curr = 0;
        curr += r.order_of_key(*r.lower_bound({a[i][0], -1}));
        curr += n - l.order_of_key(*l.lower_bound({a[i][1], n}));
        ans = min(ans, curr);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
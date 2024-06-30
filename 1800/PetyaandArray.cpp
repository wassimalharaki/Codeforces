#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

template<typename T>
using indexed_set = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, t; cin >> n >> t;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int x = 0, ans = 0;;
    indexed_set<pair<int, int>> ok;
    ok.insert({0, INT_MIN});
    for (int i = 0; i < n; i++) {
        x += a[i];
        auto it = ok.upper_bound({x - t, INT_MAX});
        if (it != ok.end())
            ans += ok.size() - ok.order_of_key(*it);
        ok.insert({x, i});
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
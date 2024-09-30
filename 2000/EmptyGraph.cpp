#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define nl '\n'
#define v vector

template<typename T>
using indexed_set = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    if (k == n) {
        cout << (int) 1e9 << nl;
        return;
    }

    indexed_set<pair<int, int>> ok;
    
    auto rem_double = [&](int i) {
        ok.erase({2 * a[i], i});
    };

    auto rem_single = [&](int i) {
        ok.erase({a[i], i});
    };

    auto add_double = [&](int i) {
        ok.insert({2 * a[i], i});
    };

    auto add_single = [&](int i) {
        ok.insert({a[i], i});
    };

    for (int i = 0; i < n; i++)
        add_double(i);
    
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        rem_double(i);
        rem_double(i + 1);
        add_single(i);
        add_single(i + 1);
        ans = max(ans, ok.find_by_order(k) -> first);
        rem_single(i);
        rem_single(i + 1);
        add_double(i);
        add_double(i + 1);
    }
    cout << min(ans, (int) 1e9) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
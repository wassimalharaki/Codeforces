#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

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

    v<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    sort(all(nums));

    ordered_set<int> ops;
    map<int, v<int>> ok;
    for (int i = 0; i < n; i++) {
        int shift = ops.size() - ops.order_of_key(nums[i].second);
        ops.insert(nums[i].second);
        ok[nums[i].first].push_back((2 * shift + nums[i].second - i) & 1);
    }

    bool my = 1;
    for (auto& [key, vals] : ok) {
        array<int, 2> cnt{0, 0};
        for (int i = 0; i < vals.size(); i++)
            cnt[i & 1] += vals[i];
        if (cnt[0] != cnt[1]) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
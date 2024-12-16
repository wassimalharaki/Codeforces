#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, q; cin >> n >> q;

    set<int> a;
    multiset<int> diff;

    auto add = [&](int x) -> void {
        auto it = a.lower_bound(x);
        int l = -1, r = -1;
        if (it != a.end()) r = *it;
        if (it != a.begin()) l = *(--it);
        if (l != -1) diff.insert(x - l);
        if (r != -1) diff.insert(r - x); 
        if (l != -1 and r != -1) 
            diff.erase(diff.find(r - l));
        a.insert(x);
    };

    auto rem = [&](int x) -> void {
        auto it = a.lower_bound(x);
        int l = -1, r = -1;
        if (++it != a.end()) r = *it;
        if (--it != a.begin()) l = *(--it);
        if (l != -1) diff.erase(diff.find(x - l));
        if (r != -1) diff.erase(diff.find(r - x));
        if (l != -1 and r != -1)
            diff.insert(r - l);
        a.erase(x);
    };

    auto ans = [&]() -> int {
        if (diff.empty()) return 0;
        return *a.rbegin() - *a.begin() - *diff.rbegin();
    };

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        add(x);
    }
    cout << ans() << nl;

    while (q--) {
        int t, x; cin >> t >> x;
        t ? add(x) : rem(x);
        cout << ans() << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
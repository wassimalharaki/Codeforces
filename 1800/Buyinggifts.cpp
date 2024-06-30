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

    v<array<int, 2>> a(n);
    for (auto& x : a)
        cin >> x[0] >> x[1];
    sort(a.begin(), a.end());
    
    int ans = 1e9;
    multiset<int> free, forced;
    for (auto& x : a)
        forced.insert(x[1]);
    
    for (auto& x : a) {
        forced.erase(forced.find(x[1]));
        int y = (forced.size() ? *forced.rbegin() : 0);
        
        auto it = free.lower_bound(x[0]);
        if (forced.size())
            ans = min(ans, abs(x[0] - y));
        if (it != free.end())
            ans = min(ans, abs(x[0] - max(*it, y)));
        if (it != free.begin())
            ans = min(ans, abs(x[0] - max(*(--it), y)));
        free.insert(x[1]);
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
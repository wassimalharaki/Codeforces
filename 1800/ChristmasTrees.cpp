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

using ai3 = array<int, 3>;

void solve() {
    int n, m; cin >> n >> m;

    priority_queue<ai3, v<ai3>, greater<ai3>> pq;
    set<int> have;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        have.insert(x);
        pq.push({1, x - 1, -1});
        pq.push({1, x + 1, 1});
    }

    int ans = 0;
    v<int> b;
    while (b.size() < m) {
        auto [x, y, z] = pq.top();
        pq.pop();
        if (have.count(y)) continue;
        ans += x;
        b.push_back(y);
        have.insert(y);
        pq.push({x + 1, y + z, z});
    }
    
    cout << ans << nl;
    for (int& x : b)
        cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
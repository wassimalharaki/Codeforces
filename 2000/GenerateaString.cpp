#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int64_t n, x, y; cin >> n >> x >> y;
    
    if (n * x <= y) {
        cout << n * x << nl;
        return;
    }

    int m = 2 * n + 1;
    v<int64_t> dis(m, LLONG_MAX); dis[n] = 0;
    v<int> vis(m);
    using ai2 = pair<int64_t, int>;
    priority_queue<ai2, v<ai2>, greater<ai2>> pq;
    pq.push({0, n});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        if (u == 0) {
            cout << d << nl;
            return;
        }

        int i = u / 2;
        if ((u & 1 ^ 1) and i < m and dis[i] > d + y) {
            dis[i] = d + y;
            pq.push({d + y, i});
        }
        i = u + 1;
        if (i < m and dis[i] > d + x) {
            dis[i] = d + x;
            pq.push({d + x, i});
        }
        i = u - 1;
        if (i >= 0 and dis[i] > d + x) {
            dis[i] = d + x;
            pq.push({d + x, i});
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
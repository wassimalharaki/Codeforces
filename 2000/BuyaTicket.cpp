#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;

void solve() {
    int n, m; cin >> n >> m;

    v<v<ai2>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--, c <<= 1;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    v<int> a(n);
    priority_queue<ai2, v<ai2>, greater<ai2>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push({a[i], i});
    }

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (a[u] < d) continue;

        for (auto& [i, c] : adj[u])
            if (d + c < a[i]) {
                a[i] = d + c;
                pq.push({a[i], i});
            }
    }
    for (int& x : a)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
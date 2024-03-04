#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (v<int>& a : adj)
        sort(all(a));

    v<int> ans, vis(n + 1);
    priority_queue<int, v<int>, greater<int>> pq;
    pq.push(1);
    while (not pq.empty()) {
        int u = pq.top();
        pq.pop();
        if (vis[u]) continue;
        ans.push_back(u);
        vis[u] = 1;
        for (int& i : adj[u])
            if (not vis[i])
                pq.push(i);
    }

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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);        
    }
    for (int i = 0; i < n - 1; i++) {
        adj[i].push_back(i + 1);
        sort(adj[i].begin(), adj[i].end());
    }

    v<int> dp(n, 1), l(n), r(n), dist(n, INT_MAX);
    v<array<int, 2>> ok;
    dist[0] = 0;

    for (int u = 0; u < n; u++) {
        int d = dist[u] + 1;
        for (int& i : adj[u]) {
            if (u + 1 < n and u + 1 <= i - d - 1)
                l[u + 1]++, r[min(n - 1, i - d - 1)]++;
            dist[i] = min(dist[i], d);
        }
    }

    int curr = 0;
    for (int i = 0; i < n - 1; i++) {
        curr += l[i];
        if (curr) dp[i] = 0;
        curr -= r[i];
    }

    for (int i = 0; i < n - 1; i++)
        cout << dp[i];
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
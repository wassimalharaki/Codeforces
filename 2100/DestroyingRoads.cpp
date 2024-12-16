#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

v<int> bfs(int src, v<v<int>>& adj) {
    int n = adj.size();
    v<int> d(n, INT_MAX);
    queue<int> q;
    q.push(src); d[src] = 0;
    
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int& i : adj[u])
            if (d[u] + 1 < d[i]) {
                d[i] = d[u] + 1;
                q.push(i);
            }
    }
    return d;
}

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    array<array<int, 3>, 2> a;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            if (j < 2) a[i][j]--;
        }
    
    v<v<int>> d(n);
    for (int i = 0; i < n; i++)
        d[i] = bfs(i, adj);
    
    if (d[a[0][0]][a[0][1]] > a[0][2])
        return void(cout << -1 << nl);
    if (d[a[1][0]][a[1][1]] > a[1][2])
        return void(cout << -1 << nl);
    
    int ans = d[a[0][0]][a[0][1]] + d[a[1][0]][a[1][1]];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int mid = d[i][j];
            array<int, 2> l{d[a[0][0]][i], d[a[1][0]][i]};
            array<int, 2> r{d[j][a[0][1]], d[j][a[1][1]]};
            {
                if (l[0] + mid + r[0] <= a[0][2]
                        and l[1] + mid + r[1] <= a[1][2])
                    ans = min(ans, mid + l[0] + l[1] + r[0] + r[1]);
            }

            l[1] = d[a[1][0]][j];
            r[1] = d[i][a[1][1]];

            {
                if (l[0] + mid + r[0] <= a[0][2]
                        and l[1] + mid + r[1] <= a[1][2])
                    ans = min(ans, mid + l[0] + l[1] + r[0] + r[1]);
            }
        }
    cout << m - ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
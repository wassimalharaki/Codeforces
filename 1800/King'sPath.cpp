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

const int N = 8;
const v<int> dx{-1, -1, -1, 0, 0, 1, 1, 1};
const v<int> dy{-1, 0, 1, -1, 1, -1, 0, 1};

void solve() {
    array<int, 2> s, e;
    cin >> s[0] >> s[1] >> e[0] >> e[1];

    int n; cin >> n;
    map<int, v<array<int, 2>>> ok;
    for (int i = 0; i < n; i++) {
        int r, a, b; cin >> r >> a >> b;
        ok[r].push_back({a, b});
    }

    //nodes and dijsktra? no need, bfs works
    int k = 0;
    map<int, v<array<int, 2>>> nodes;
    nodes[s[0]].push_back({s[1], k++});
    for (auto& [c, a] : ok) {
        sort(a.begin(), a.end());
        v<array<int, 2>> b{a[0]};
        for (int i = 1; i < a.size(); i++)
            if (a[i][0] <= b.back()[1])
                b.back()[1] = max(b.back()[1], a[i][1]);
            else
                b.push_back(a[i]);
        a.swap(b);
        for (auto& [l, r] : a)
            for (int i = l; i <= r; i++)
                nodes[c].push_back({i, k++});
    }
    nodes[e[0]].push_back({e[1], k++});
    sort(nodes[s[0]].begin(), nodes[s[0]].end());
    sort(nodes[e[0]].begin(), nodes[e[0]].end());

    v<v<int>> adj(k);
    for (auto& [r, a] : nodes)
        for (auto& [c, j] : a)
            for (int i = 0; i < N; i++) {
                int x = r + dx[i], y = c + dy[i];
                if (not nodes.count(x)) continue;
                auto& b = nodes[x];
                auto it = lower_bound(b.begin(), b.end(),
                        array<int, 2>{y, 0});
                if (it == b.end()) continue;
                if ((*it)[0] != y) continue;
                adj[j].push_back((*it)[1]);
                adj[(*it)[1]].push_back(j);
            }

    v<int> vis(k), dis(k, LLONG_MAX);
    queue<int> q;
    vis[0] = 1, dis[0] = 0;
    q.push(0);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int& i : adj[u])
            if (not vis[i]) {
                dis[i] = dis[u] + 1;
                vis[i] = 1;
                q.push(i);
            }
    }
    cout << (dis[k - 1] == LLONG_MAX ? -1 : dis[k - 1]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
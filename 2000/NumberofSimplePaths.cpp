#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(V + E)
vector<int> comp, comps;
void tarjan(vector<vector<int>>& adj) {
    int n = adj.size(), curr = 0;
    comps.clear();
    comp.assign(n, -1);
    vector<int> disc(n), vis;

    auto dfs = [&](int u, int p, auto&& dfs) -> int {
        int low = disc[u] = ++curr;
        vis.push_back(u);

        for (int& i : adj[u])
            if (i != p and comp[i] == -1)
                low = min(low, disc[i] ?: dfs(i, u, dfs));

        if (low == disc[u]) {
            comps.push_back(u);
            for (int i = -1; i != u;) {
                i = vis.back();
                comp[i] = u;
                vis.pop_back();
            }
        }
        return low;
    };

    for (int i = 0; i < n; i++)
        if (!disc[i]) dfs(i, -1, dfs);
    reverse(comps.begin(), comps.end());
}

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tarjan(adj);

    int c = 0;
    v<int> cnt(n);
    for (int i = 0; i < n; i++)
        c = max(c, ++cnt[comp[i]]);
    
    int sz = 0;
    v<int> out, vis(n);
    auto dfs = [&](int u, auto&& dfs) -> void {
        if (vis[u]) return;
        sz++; vis[u] = 1;
        for (int& i : adj[u])
            dfs(i, dfs);
    };

    for (int i = 0; i < n; i++)
        if (cnt[comp[i]] == c)
            vis[i] = 1;
    for (int i = 0; i < n; i++)
        if (cnt[comp[i]] == c) {
            sz = -1;
            vis[i] = 0;
            dfs(i, dfs);
            if (sz) out.push_back(sz);
        }
    
    int x = accumulate(out.begin(), out.end(), 0ll);
    int ans = c * (c - 1) + x * x;
    for (int& b : out)
        ans += 2 * b * (c - 1) + (b + 1) * b / 2 - b * b;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
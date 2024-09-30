#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(V + E)
vector<int> comp, comps;
void tarjan(const vector<vector<int>>& adj) {
    int n = adj.size(), curr = 0;
    comps.clear();
    comp.assign(n, -1);
    vector<int> disc(n), vis;

    auto dfs = [&](int u, auto&& dfs) -> int {
        int low = disc[u] = ++curr;
        vis.push_back(u);

        for (const int& i : adj[u])
            if (comp[i] == -1)
                low = min(low, disc[i] ?: dfs(i, dfs));

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
        if (not disc[i]) dfs(i, dfs);
    reverse(comps.begin(), comps.end());
}

// O(V + E)
vector<int> topsort(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<char> vis(n);
    vector<int> order;

    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        for (const int& i : adj[u])
            if (not vis[i])
                dfs(i, dfs);
        order.push_back(u);
    };

    for (int i = 0; i < n; i++)
        if (not vis[i]) dfs(i, dfs);
    reverse(order.begin(), order.end());

    return order;
}

void solve() {
    int n, m; cin >> n >> m;

    v<int> self(n), ans(n);
    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (a == b) self[a - 1] = 1;
        else adj[a - 1].push_back(b - 1);
    }
    tarjan(adj);

    int k = 0;
    v<int> id(n);
    for (int& u : comps)
        id[u] = k++;
    v<int> sz(k);
    for (int& u : comp)
        sz[u = id[u]]++;

    for (int i = 0; i < n; i++)
        if (self[i])
            sz[comp[i]]++;

    v<v<int>> dag(k);
    for (int i = 0; i < n; i++)
        for (int& u : adj[i])
            dag[comp[i]].push_back(comp[u]);

    ans[comp[0]] = 1;
    auto ts = topsort(dag);
    for (int& u : ts) {
        if (ans[u] == 0) continue;
        if (sz[u] > 1) ans[u] = -1;

        if (ans[u] == 1)
            for (int& i : dag[u]) {
                if (ans[i] != -1)
                    ans[i] = min(2ll, ans[i] + 1);
            }
        else if (ans[u] == -1)
            for (int& i : dag[u])
                ans[i] = -1;
        else
            for (int& i : dag[u])
                if (ans[i] != -1)
                    ans[i] = 2;
    }

    for (int i = 0; i < n; i++)
        cout << ans[comp[i]] << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
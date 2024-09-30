#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(V + E)
vector<int> comp, comps;
void tarjan(vector<vector<int>>& adj) {
    int n = adj.size(), curr = 0;
    comps.clear();
    comp.assign(n, -1);
    vector<int> disc(n), vis;

    auto dfs = [&](int u, auto&& dfs) -> int {
        int low = disc[u] = ++curr;
        vis.push_back(u);

        for (int& i : adj[u])
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
        if (!disc[i]) dfs(i, dfs);
    reverse(comps.begin(), comps.end());
}

// O(V + E)
vector<int> topsort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<char> vis(n);
    vector<int> order;

    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        for (int& i : adj[u])
            if (not vis[i])
                dfs(i, dfs);
        order.push_back(u);
    };

    for (int i = 0; i < n; i++)
        if (not vis[i]) dfs(i, dfs);
    reverse(order.begin(), order.end());

    return order;
}

const int N = 5001;

void solve_dag(v<v<int>>& adj, int s) {
    int n = adj.size();

    vector<bitset<N>> reach(n);
    auto dfs = [&](int u, auto&& dfs) -> void {
        if (reach[u][u]) return;
        reach[u][u] = 1;
        for (int& i : adj[u]) {
            dfs(i, dfs);
            reach[u] |= reach[i];
        }
    };

    for (int i = 0; i < n; i++)
        if (not reach[i][i])
            dfs(i, dfs);
    
    int ans = 0;
    v<int> ts = topsort(adj);
    for (int& u : ts)
        if (not reach[s][u]) {
            ans++;
            reach[s] |= reach[u];
        }
    cout << ans << nl;
}

void solve() {
    int n, m, s; cin >> n >> m >> s;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    tarjan(adj);

    int k = 0;
    v<int> id(n);
    for (int& u : comps)
        id[u] = k++;

    v<v<int>> dag(comps.size());
    for (int u = 0; u < n; u++)
        for (int& i : adj[u])
            if (comp[u] != comp[i])
                dag[id[comp[u]]].push_back(id[comp[i]]);
    
    for (int i = 0; i < (int) comps.size(); i++) {
        sort(dag[i].begin(), dag[i].end());
        dag[i].resize(unique(dag[i].begin(), dag[i].end()) - dag[i].begin());
    }
    solve_dag(dag, id[comp[s - 1]]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

vector<int> centroid_decomp(const vector<vector<int>>& adj) {
    vector<int> sz(adj.size()), par(adj.size()), dead(adj.size());

    auto find_size = [&](int u, int p, auto&& self) -> int {
        sz[u] = 1;
        for (const int& i : adj[u])
            if (i != p and not dead[i])
                sz[u] += self(i, u, self);
        return sz[u];
    };

    auto find_centroid = [&](int u, int p, int n, auto&& self) -> int {
        for (const int& i : adj[u])
            if (i != p and not dead[i] and sz[i] > n / 2)
                return self(i, u, n, self);
        return u;
    };

    auto build = [&](int u, int p, auto&& self) -> void {
        int n = find_size(u, p, find_size);
        int cent = find_centroid(u, p, n, find_centroid);
        par[cent] = p;
        dead[cent] = 1;

        for (const int& i : adj[cent])
            if (i != p and not dead[i])
                self(i, cent, self);
    };
    build(0, -1, build);
    return par;
}

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    v<int> p = centroid_decomp(adj);
    adj.assign(n, v<int>());

    int rt = 0;
    for (int i = 0; i < n; i++)
        if (p[i] == -1)
            rt = i;
        else
            adj[p[i]].push_back(i);
    
    v<char> ans(n);
    auto dfs = [&](int u, char c, auto&& self) -> void {
        ans[u] = c++;
        for (int& i : adj[u])
            self(i, c, self);
    };
    dfs(rt, 'A', dfs);
    
    for (char& c : ans)
        cout << c << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
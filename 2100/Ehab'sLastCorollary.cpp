#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(V + E)
vector<int> get_cycle(const vector<vector<int>>& adj) {
    int n = adj.size(), l = -1, r = -1;
    vector<int> p(n, -1);
    vector<char> c(n);
    
    auto dfs = [&](int u, int par, auto&& self) -> bool {
        c[u] = 1;
        for (const int& i : adj[u]) if (i != par) {
            
            if (c[i] == 0) {
                p[i] = u;
                if (self(i, u, self))
                    return 1;
            }
            else if (c[i] == 1) {
                l = i;
                r = u;
                return 1;
            }
        }
        c[u] = 2;
        return 0;
    };

    for (int i = 0; i < n; i++)
        if (c[i] == 0 and dfs(i, -1, dfs))
            break;
    if (r == -1) return {};

    vector<int> cycle{l};
    for (int u = r; u != l; u = p[u])
        cycle.push_back(u);
    cycle.push_back(l);
    reverse(cycle.begin(), cycle.end());

    return cycle;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<v<int>> adj(n);
    v<array<int, 2>> e(m);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        e[i] = {--a, --b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (m == n - 1) {
        array<v<int>, 2> a;
        auto dfs = [&](int u, int p, bool b, auto&& self) -> void {
            a[b].push_back(u);
            for (int& i : adj[u])
                if (i != p) self(i, u, !b, self);
        };
        dfs(0, -1, 0, dfs);

        if (a[0].size() < a[1].size())
            swap(a[0], a[1]);

        cout << 1 << nl;
        for (int i = 0; i < (k + 1) / 2; i++)
            cout << a[0][i] + 1 << " ";
        cout << nl;
        return;
    }

    auto c = get_cycle(adj); c.pop_back();
    v<int> ind(n, -1);
    for (int i = 0; i < (int) c.size(); i++)
        ind[c[i]] = i;

    int l = 0, r = c.size() - 1;
    for (auto& [a, b] : e)
        if (ind[a] != -1 and ind[b] != -1) {
            int mx = max(ind[a], ind[b]);
            int mn = min(ind[a], ind[b]);
            if (mx - mn != 1 and mx - mn < r - l)
                l = mn, r = mx;
        }
    c = vector<int>(c.begin() + l, c.begin() + r + 1);

    if ((int) c.size() <= k) {
        cout << 2 << nl;
        cout << c.size() << nl;
        for (int& x : c)
            cout << x + 1 << " ";
        cout << nl;
    }
    else {
        cout << 1 << nl;
        for (int i = 0; i < (k + 1) / 2; i++)
            cout << c[2 * i] + 1 << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
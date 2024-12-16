#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(V + E)
struct two_sat {
    int n;
    vector<bool> ans;
    vector<vector<int>> adj;

    two_sat(int _n) {
        n = _n;
        ans.resize(_n);
        adj.resize(2 * _n);
    }

    void add_clause(int i, bool f, int j, bool g) {
        adj[2 * i + !f].push_back(2 * j + g);
        adj[2 * j + !g].push_back(2 * i + f);
    }

    vector<int> tarjan() {
        int curr = 0, grp_id = 0;
        vector<int> disc(2 * n), id(2 * n, -1), vis;

        auto dfs = [&](int u, auto&& self) -> int {
            int low = disc[u] = ++curr;
            vis.push_back(u);

            for (int& i : adj[u])
                if (id[i] == -1)
                    low = min(low, disc[i] ?: self(i, self));

            if (low == disc[u]) {
                for (int i = -1; i != u;) {
                    i = vis.back();
                    id[i] = grp_id;
                    vis.pop_back();
                }
                grp_id++;
            }
            return low;
        };

        for (int i = 0; i < 2 * n; i++)
            if (!disc[i]) dfs(i, dfs);
        return id;
    }

    bool satisfiable() {
        vector<int> id = tarjan();
        for (int i = 0; i < n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return 0;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return 1;
    }

    vector<bool> answer() { return ans; }
};

bool intersect(array<int, 2> x, array<int, 2> y) {
    if (x[0] == y[0] or x[1] == y[1] or x[0] == y[1] or x[1] == y[0])
        return 0;
    if (x[0] > x[1]) swap(x[0], x[1]);
    bool a = x[0] < y[0] and y[0] < x[1];
    bool b = x[0] < y[1] and y[1] < x[1];
    return (a and not b) or (b and not a);
}

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 2>> e(m);
    for (auto& [x, y] : e)
        cin >> x >> y;
    
    two_sat ts(m);
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (intersect(e[i], e[j])) {
                ts.add_clause(i, 1, j, 1);
                ts.add_clause(i, 0, j, 0);
            }

    if (not ts.satisfiable())
        cout << "Impossible" << nl;
    else {
        auto ans = ts.answer();
        for (int i = 0; i < m; i++)
            cout << (ans[i] ? 'o' : 'i');
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
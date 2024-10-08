#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

template <class E> struct csr {
    vector<int> start;
    vector<E> elist;
    csr(int n, const vector<pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges)
            start[e.first + 1]++;

        for (int i = 1; i <= n; i++)
            start[i] += start[i - 1];
            
        auto counter = start;
        for (auto e : edges)
            elist[counter[e.first]++] = e.second;
    }
};

struct scc_graph {
    int _n;
    struct edge {
        int to;
    };
    vector<pair<int, edge>> edges;

    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    pair<int, vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);

        auto dfs = [&](int u, auto&& dfs) -> void {
            low[u] = ord[u] = now_ord++;
            visited.push_back(u);
            for (int i = g.start[u]; i < g.start[u + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    dfs(to, dfs);
                    low[u] = min(low[u], low[to]);
                }
                else
                    low[u] = min(low[u], ord[to]);
            }
            if (low[u] == ord[u]) {
                while (true) {
                    int i = visited.back();
                    visited.pop_back();
                    ord[i] = _n;
                    ids[i] = group_num;
                    if (i == u) break;
                }
                group_num++;
            }
        };

        for (int i = 0; i < _n; i++)
            if (ord[i] == -1) dfs(i, dfs);
        for (auto& x : ids)
            x = group_num - 1 - x;
        return {group_num, ids};
    }

    vector<vector<int>> scc() {
        auto ids = scc_ids();

        int group_num = ids.first;
        vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;

        vector<vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++)
            groups[i].reserve(counts[i]);

        for (int i = 0; i < _n; i++)
            groups[ids.second[i]].push_back(i);
        return groups;
    }
};

// O(V + E)
struct two_sat {
    int _n;
    vector<bool> _answer;
    scc_graph scc;

    two_sat() : _n(0), scc(0) {}
    two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }

    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return 0;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return 1;
    }
    
    vector<bool> answer() { return _answer; }
};

v<int> dx{1, 0};
v<int> dy{0, 1};

void solve() {
    int n, m; cin >> n >> m;

    v a(n, v<int>(m));
    for (auto& x : a)
        for (auto& y : x)
            cin >> y;

    auto valid = [&](int i, int j) {
        return i < n and j < m;
    };
    
    two_sat ts(n * m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 2; k++) {
                int r = i + dx[k], c = j + dy[k];
                if (not valid(r, c)) continue;
                if (a[i][j] == a[r][c]) {
                    ts.add_clause(i * m + j, 1, r * m + c, 1);
                    ts.add_clause(i * m + j, 0, r * m + c, 0);
                }
                else if (abs(a[i][j] - a[r][c]) == 1) {
                    ts.add_clause(i * m + j, 1, r * m + c, 0);
                    ts.add_clause(i * m + j, 0, r * m + c, 1);
                }
            }
    ts.satisfiable();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << a[i][j] + ts._answer[i * m + j] << " \n"[j + 1 == m];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
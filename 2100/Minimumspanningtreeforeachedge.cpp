#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using S = int;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return 0;
}

// O(nlog(n)), O(1)
// template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
    vector<vector<S>> d;

    sparse_table(vector<S>& a) {
        if (a.empty()) return;
        int n = a.size(), k = 64 - __builtin_clzll(n);
        d.resize(k, vector<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        if (l == r) return e();
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

// O(n), O(1)
struct DSU {
    vector<int> p;

    DSU(int n) {
        p.resize(n, -1);
    }

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    int size(int x) {
        return - p[find(x)];
    }

    bool same_set(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        return true;
    }
};

// O(n)
v<array<int, 4>> tree;
int64_t kruskal(int n, vector<array<int, 4>>& e) {
    DSU ds(n + 1);
    int64_t w = 0, j = 0;
    for (auto& [c, a, b, i] : e) {
        if (not ds.merge(a, b)) continue;
        tree.push_back({c, a, b, i});
        w += c;
        if (++j == n - 1) break;
    }
    return (j == n - 1 ? w : -1);
}

void solve() {
    int n, m; cin >> n >> m;

    v<v<array<int, 2>>> adj(n);
    v<array<int, 4>> e(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        e[i] = {c, --a, --b, i};
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    sort(e.begin(), e.end());

    v<int64_t> ans(m);
    v<list<int>> lt(n);
    for (int i = 0; i < n; i++)
        lt[i].push_back(i);
    
    DSU ds(n);
    int64_t w = kruskal(n, e);
    for (auto& [c, a, b, i] : tree) {
        ans[i] = w;
        int pa = ds.find(a), pb = ds.find(b);
        if (ds.p[pa] > ds.p[pb]) swap(pa, pb);
        lt[pa].push_back(c);
        lt[pa].splice(lt[pa].end(), lt[pb]);
        ds.merge(pa, pb);
    }

    v<int> in(n), d;
    int k = 0;
    bool par = 0;
    for (int& x : lt[ds.find(0)]) {
        if (par)
            d.push_back(x);
        else
            in[x] = k++;
        par = !par;
    }

    sparse_table max_table(d);
    for (auto& [c, a, b, i] : e) {
        if (ans[i]) continue;
        int l = min(in[a], in[b]), r = max(in[a], in[b]);
        ans[i] = w - max_table.prod(l, r) + c;
    }

    for (int64_t& x : ans)
        cout << x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
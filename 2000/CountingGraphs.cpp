#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(n), O(log(n))
struct DSU {
    int comp;
    vector<int> p;
    vector<array<int, 5>> hist;

    DSU(int n) { p.resize(n, -1); comp = n; }

    int find(int x) {
        return p[x] < 0 ? x : find(p[x]);
    }

    int size(int x) { return - p[find(x)]; }

    bool same_set(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x); y = find(y);
        hist.push_back({x, p[x], y, p[y], comp});
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        comp--; return true;
    }

    void rollback() {
        auto [x, sx, y, sy, c] = hist.back();
        p[x] = sx; p[y] = sy; comp = c;
        hist.pop_back();
    }
};

struct dc_graph {
    int n, size, t;
    vector<array<int, 2>> q;
    vector<array<int, 3>> e; 
    vector<vector<array<int, 2>>> d;

    dc_graph(int _n, int _q) {
        t = 0, n = _n;
        size = bit_ceil(_q);
        q.resize(size, {-1, -1});
        d.resize(size << 1);
    }

    int bit_ceil(int _n) {
        int x = 1;
        while (x < _n) x <<= 1;
        return x;
    }

    void add_edge(int a, int b) {
        if (a > b) swap(a, b);
        e.push_back({a, b, t++});
    }

    void erase_edge(int a, int b) {
        if (a > b) swap(a, b);
        e.push_back({a, b, t++});
    }

    void query(int a, int b) { q[t++] = {a, b}; }

    void apply(int l, int r, array<int, 2> x) {
        l += size, r += size;
        while (l < r) {
            if (l & 1) d[l++].push_back(x);
            if (r & 1) d[--r].push_back(x);
            l >>= 1; r >>= 1;
        }
    }

    vector<int64_t> solve() {
        int m = e.size();
        sort(e.begin(), e.end());

        for (int i = 0; i < m; i++)
            if (i == m - 1)
                apply(e[i][2], t, {e[i][0], e[i][1]});
            else if (e[i][0] == e[i + 1][0] and e[i][1] == e[i + 1][1])
                apply(e[i][2], e[i + 1][2], {e[i][0], e[i][1]}), i++;
            else
                apply(e[i][2], t, {e[i][0], e[i][1]});

        DSU ds(n);
        vector<int64_t> ans;
        auto dfs = [&](int i, auto&& dfs) -> void {
            for (auto& [a, b] : d[i])
                ds.merge(a, b);

            if (i < size) {
                dfs(i << 1, dfs);
                dfs((i << 1) + 1, dfs);
            }
            else if (q[i - size][0] != -1) {
                int a = ds.size(q[i - size][0]);
                int b = ds.size(q[i - size][1]);
                ans.push_back(1ll * a * b - 1);
            }
            
            for (int j = 0; j < (int) d[i].size(); j++)
                ds.rollback();
        };
        dfs(1, dfs);

        return ans;
    }
};

const int mod = 998244353;

// O(log(b))
int64_t binpow(int64_t a, int64_t b, const int m = mod) {
    a %= m;
    int64_t res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, s; cin >> n >> s;

    v<array<int, 3>> e(n - 1);
    dc_graph dc(n, 3 * n - 3);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        e[i] = {c, --a, --b};
        dc.add_edge(a, b);
    }
    sort(e.rbegin(), e.rend());

    for (auto& [c, a, b] : e) {
        dc.erase_edge(a, b);
        dc.query(a, b);
    }

    int64_t ans = 1;
    auto x = dc.solve();
    for (int i = 0; i < n - 1; i++)
        ans = ans * binpow(s - e[i][0] + 1, x[i]) % mod;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
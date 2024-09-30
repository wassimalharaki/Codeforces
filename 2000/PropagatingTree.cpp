#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;
using S = ai2;

ai2 op(ai2 a, ai2 b) {
    return a;
}

ai2 e() {
    return {0, 0};
}

using F = int;

ai2 mapping(int x, ai2 a, int c) {
    a[1] += (a[0] & 1 ? -1 : 1) * x;
    return a;
}

int composition(int x, int y) {
    return x + y;
}

int id() {
    return 0;
}

// O(n), O(log(n))
// template <class S,
//           S (*op)(S, S),
//           S (*e)(),
//           class F,
//           S (*mapping)(F, S, int),
//           F (*composition)(F, F),
//           F (*id)()>
struct lazy_segtree {
    int n, size, log;
    vector<S> d;
    vector<F> lz;

    lazy_segtree(int _n) : lazy_segtree(vector<S>(_n, e())) {}

    lazy_segtree(const vector<S>& a) {
        n = a.size();
        size = bit_ceil(n);
        log = __builtin_ctz(size);
        d.resize(size << 1, e());
        lz.resize(size, id());
        for (int i = 0; i < n; i++) d[size + i] = a[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    void update(int k) {
        d[k] = op(d[k << 1], d[(k << 1) + 1]);
    }

    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k], 1 << (log - __lg(k)));
        if (k < size) lz[k] = composition(f, lz[k]);
    }

    void push(int k) {
        all_apply(k << 1, lz[k]);
        all_apply((k << 1) + 1, lz[k]);
        lz[k] = id();
    }

    int bit_ceil(int _n) {
        int x = 1;
        while (x < n) x <<= 1;
        return x;
    }

    void set(int p, S x) {
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        if (l == r) return e();
        l += size, r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p], 1);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void apply(int l, int r, F f) {
        if (l == r) return;
        l += size, r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
};

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int t = 0;
    v<int> in(n), out(n), depth(n);
    v<ai2> euler;
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        in[u] = t++;
        depth[u] = d;
        euler.push_back({d, a[u]});

        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, d + 1, dfs);
        out[u] = t;
    };
    dfs(0, -1, 0, dfs);

    lazy_segtree seggy(euler);
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        if (c == 1) {
            int u, x; cin >> u >> x;
            u--;
            if (depth[u] & 1)
                x = - x;
            seggy.apply(in[u], out[u], x);
        }
        else {
            int u; cin >> u;
            cout << seggy.get(in[u - 1])[1] << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using S = int;
int op(int a, int b) { return a + b; }
int e() { return 0; }
using F = int;
int mapping(int x, int a, int c) { return a + x * c; }
int composition(int x, int y) { return x + y; }
int id() { return 0; }

// O(n), O(log(n))
struct lazy_segtree {
    int n, size, log;
    vector<S> d;
    vector<F> lz;

    lazy_segtree(int _n) : lazy_segtree(vector<S>(_n, e())) {}

    lazy_segtree(const vector<S>& a) {
        n = a.size();
        size = n <= 1 ? 1 : 1 << (1 + __lg(n - 1));
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

bool isect(v<array<int, 2>>& a) {
    sort(a.begin(), a.end());
    int r = -1;
    for (auto& [x, y] : a)
        if (x <= r)
            return 1;
        else
            r = y;
    return 0;
}

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n), b(n);
    int m;
    {

        v<int> c;
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1]
                >> b[i][0] >> b[i][1];
            c.insert(c.end(), {
                a[i][0], a[i][1],
                b[i][0], b[i][1]
            });
        }
        sort(c.begin(), c.end());
        c.resize(unique(c.begin(), c.end()) - c.begin());

        auto get = [&](int x) {
            return lower_bound(c.begin(), c.end(), x) - c.begin();  
        };

        for (auto& [x, y] : a)
            x = get(x), y = get(y);
        for (auto& [x, y] : b)
            x = get(x), y = get(y);
        m = c.size();
    }
    bool ans = 0;

    v<int> vis(n);
    v<array<int, 3>> c(2 * n);
    lazy_segtree seggy(m);

    for (int i = 0; i < n; i++)
        c[2 * i] = {a[i][0], -1, i},
        c[2 * i + 1] = {a[i][1], 1, i};
    sort(c.begin(), c.end());

    for (auto& [x, _, i] : c)
        if (vis[i])
            seggy.apply(b[i][0], b[i][1] + 1, 1);
        else {
            vis[i] = 1;
            ans |= seggy.prod(b[i][0], b[i][1] + 1);
        }
    
    for (int i = 0; i < m; i++)
        seggy.set(i, 0);

    for (int i = 0; i < n; i++)
        swap(a[i], b[i]);
    
    for (int i = 0; i < n; i++) {
        c[2 * i] = {a[i][0], -1, i};
        c[2 * i + 1] = {a[i][1], 1, i};
        vis[i] = 0;
    }
    sort(c.begin(), c.end());

    for (auto& [x, _, i] : c)
        if (vis[i])
            seggy.apply(b[i][0], b[i][1] + 1, 1);
        else {
            vis[i] = 1;
            ans |= seggy.prod(b[i][0], b[i][1] + 1);
        }
    cout << (ans ? "NO" : "YES") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

using S = int;
using F = int;
int op(int a, int b) { return min(a, b); }
int e() { return INT_MAX; }
int mapping(int x, int a, int c) { return a + x; }
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

const int N = 1e6 + 1;

void solve() {
    int n, m; cin >> n >> m;
    m <<= 1, m--;

    v<array<int, 3>> a(n);
    for (auto& [l, r, x] : a) {
        cin >> l >> r >> x; l--;
        l <<= 1, r <<= 1;
        r = min(r - 1, m);
    }
    sort(a.begin(), a.end(), [](auto l, auto& r) {
        return l[2] < r[2];
    });

    lazy_segtree seggy(m);
    seggy.apply(0, m, -INT_MAX);

    int i = 0, j = 0, ans = 1e9;
    for (int l = 1; l < N; l++) {
        for (; i < n and a[i][2] < l; i++)
            if (i < j)
                seggy.apply(a[i][0], a[i][1], -1);
        for (j = max(i, j); j < n and !seggy.prod(0, m); j++)
            seggy.apply(a[j][0], a[j][1], 1);
        if (!seggy.prod(0, m)) break;
        ans = min(ans, a[j - 1][2] - a[i][2]);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai4 = array<int, 4>;
ai4 op(ai4 a, ai4 b) {
    return {
        max({
            a[0], b[0],
            a[0] + b[2],
            a[1] + b[0]
        }),
        max({
            a[1], b[1],
            a[0] + b[3],
            a[1] + b[1]
        }),
        max({
            a[2], b[2],
            a[2] + b[2],
            a[3] + b[0]
        }),
        max({
            a[3], b[3],
            a[2] + b[3],
            a[3] + b[1]
        })
    };
}
ai4 e() { ai4 a; a.fill(-1e18); return a; }

// O(n), O(log(n))
template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n, size, log;
    vector<S> d;

    segtree(int _n) : segtree(vector<S>(_n, e())) {}
    
    segtree(const vector<S>& a) {
        n = a.size();
        size = n <= 1 ? 1 : 1 << (1 + __lg(n - 1));
        log = __builtin_ctz(size);
        d.resize(size << 1, e());
        for (int i = 0; i < n; i++) d[size + i] = a[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    void update(int k) {
        d[k] = op(d[k << 1], d[(k << 1) + 1]);
    }

    void set(int p, S x) {
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        return d[p + size];
    }

    S prod(int l, int r) const {
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }
};

void solve() {
    int n, q; cin >> n >> q;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<ai4> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], - a[i], - a[i], - a[i]};
    segtree<ai4, op, e> seggy(b);
    cout << seggy.d[1][0] << nl;

    while (q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        seggy.set(l, b[r]);
        seggy.set(r, b[l]);
        swap(b[l], b[r]);
        cout << seggy.d[1][0] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
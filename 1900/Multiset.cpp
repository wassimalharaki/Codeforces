#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

using S = int;

int op(int a, int b) {
    return a + b;
}

int e() {
    return 0;
}

// O(n), O(log(n))
// template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int n, size, log;
    vector<S> d;

    segtree(int _n) : segtree(vector<S>(_n, e())) {}
    
    segtree(const vector<S>& a) {
        n = a.size();
        size = bit_ceil(n);
        log = __builtin_ctz(size);
        d.resize(size << 1, e());
        for (int i = 0; i < n; i++) d[size + i] = a[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    void update(int k) {
        d[k] = op(d[k << 1], d[(k << 1) + 1]);
    }

    int bit_ceil(int _n) {
        int x = 1;
        while (x < n) x <<= 1;
        return x;
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

    segtree seggy(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        seggy.set(x, seggy.get(x) + 1);
    }

    while (q--) {
        int k; cin >> k;
        if (k >= 1) {
            seggy.set(k, seggy.get(k) + 1);
            continue;
        }
        k *= -1;
        int i = 1;
        while (i < seggy.size)
            if (seggy.d[i << 1] >= k)
                i <<= 1;
            else {
                k -= seggy.d[i << 1];
                i = (i << 1) + 1;
            }
        i -= seggy.size;
        seggy.set(i, seggy.get(i) - 1);
    }
    for (int i = 1; i <= n; i++)
        if (seggy.get(i)) {
            cout << i << nl;
            return;
        }
    cout << 0 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
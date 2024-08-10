#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int e() {
    return 0;
}

// O(n), O(log(n))
template <class S, S (*op)(S, S), S (*e)()>
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
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    segtree<int, op, e> seggy(a);

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 2) {
            int i, x; cin >> i >> x;
            seggy.set(--i, x);
            continue;
        }

        int l, r, x; cin >> l >> r >> x;
        l--;
        if (op(seggy.prod(l, r), x) == x) {
            cout << "YES" << nl;
            continue;
        }

        int lo = l, hi = r - 1, i = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (op(seggy.prod(l, mid + 1), x) != x)
                i = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        int prev = seggy.get(i);
        seggy.set(i, x);
        cout << (op(seggy.prod(l, r), x) == x ? "YES" : "NO") << nl;
        seggy.set(i, prev);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return a + b;
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
    
    v<int> b(n + 1);
    iota(b.begin(), b.end(), 0);
    segtree<int, op, e> seggy(b);

    auto walk = [&](int x) -> int {
        int i = 1;
        while (i < seggy.size)
            if (seggy.d[i << 1] > x)
                i = i << 1;
            else
                x -= seggy.d[i << 1],
                i = (i << 1) + 1;
        return i - seggy.size;
    };

    v<int> a(n), ans(n);
    for (int& x : a) cin >> x;

    for (int i = n - 1; i >= 0; i--) {
        int j = walk(a[i]);
        ans[i] = j;
        seggy.set(j, 0);
    }

    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
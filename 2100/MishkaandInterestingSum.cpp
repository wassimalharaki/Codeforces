#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int op(int a, int b) { return a ^ b; }
int e() { return 0; }

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
    int n; cin >> n;

    v<int> a(n), pref(n + 1);
    for (int& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), pref.begin() + 1, bit_xor<int>());

    v<int> c(a.begin(), a.end());
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());

    auto get = [&](int x) -> int {
        return lower_bound(c.begin(), c.end(), x) - c.begin();
    };

    int q; cin >> q;
    v<v<array<int, 2>>> b(n);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        b[l - 1].push_back({r, i});
    }

    v<int> ans(q), in(c.size(), -1);
    segtree<int, op, e> seggy(n);
    for (int i = n - 1; i >= 0; i--) {
        int k = get(a[i]);
        if (in[k] != -1)
            seggy.set(in[k], e());
        seggy.set(i, a[i]);
        in[k] = i;

        for (auto& [r, j] : b[i])
            ans[j] = pref[r] ^ pref[i] ^ seggy.prod(i, r);
    }

    for (int& x : ans)
        cout << x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
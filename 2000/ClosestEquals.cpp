#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return min(a, b);
}

int e() {
    return INT_MAX;
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
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<array<int, 2>>> rb(n);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        rb[r - 1].push_back({l - 1, i});
    }

    v<int> ans(m);
    map<int, array<int, 2>> have;
    segtree<int, op, e> seggy(n);
    for (int r = 0; r < n; r++) {
        if (not have.count(a[r])) {
            have[a[r]] = {r, -1};
        }
        else if (have[a[r]][1] == -1) {
            seggy.set(have[a[r]][0], r - have[a[r]][0]);
            have[a[r]][1] = r;
        }
        else {
            have[a[r]] = {have[a[r]][1], r};
            seggy.set(have[a[r]][0], r - have[a[r]][0]);
        }
        for (auto& [l, i] : rb[r])
            ans[i] = seggy.prod(l, r + 1);
    }

    for (int& x : ans)
        cout << (x == e() ? -1 : x) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
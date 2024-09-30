#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

using ai3 = array<int, 3>;
ai3 op(ai3 a, ai3 b) {
    if (a[0] == -1)
        return b;
    if (b[0] == -1)
        return a;
    return {a[0], a[1] and b[1] and a[2] <= b[0], b[2]};
}
ai3 e() { return {-1, 1, -1}; }

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
    int n, m; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    {
        auto b = a;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        m = b.size();
        for (int& x : a)
            x = lower_bound(b.begin(), b.end(), x) - b.begin();
    }

    v<v<int>> pos(m);
    for (int i = 0; i < n; i++)
        pos[a[i]].push_back(i);
    
    v<ai3> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], 1, a[i]};
    segtree<ai3, op, e> seggy(b);

    int l = 0, r = m - 1, ans = m;
    while (not seggy.all_prod()[1])
        for (int& i : pos[l++])
            seggy.set(i, e());
    ans = min(ans, l);
    while (--l >= 0) {
        for (int& i : pos[l])
            seggy.set(i, b[i]);
        while (not seggy.all_prod()[1])
            for (int& i : pos[r--])
                seggy.set(i, e());
        ans = min(ans, l + m - r - 1);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
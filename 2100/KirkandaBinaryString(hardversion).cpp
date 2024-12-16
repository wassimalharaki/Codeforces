#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

using ai3 = array<int, 3>;
ai3 op(ai3 a, ai3 b) { 
    return {
        a[0] + b[0],
        a[1] + b[1],
        max(a[2] + b[1], b[2] + a[0])
    };
}
ai3 e() { return {0, 0, 0}; }

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

    S get(int p) {
        return d[p + size];
    }

    S prod(int l, int r) {
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

    S all_prod() { return d[1]; }
};

void solve() {
    string s; cin >> s;
    int n = s.size();
    string t = s;

    segtree<ai3, op, e> seggy1(n), seggy2(n);
    for (int i = 0; i < n; i++) {
        seggy1.set(i, {s[i] == '0', s[i] == '1', 1});
        seggy2.set(i, {t[i] == '0', t[i] == '1', 1});
    }

    for (int i = n - 1; i >= 0; i--) {
        if (t[i] == '0') continue;
        if (i + 1 < n and s[i + 1] == '0') continue;

        t[i] = '0';
        seggy2.set(i, {1, 0, 1});
        if (seggy1.prod(i, n)[2] != seggy2.prod(i, n)[2]) {
            seggy2.set(i, {0, 1, 1});
            t[i] = '1';
        }
    }
    cout << t << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
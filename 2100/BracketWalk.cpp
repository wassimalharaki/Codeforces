#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;
using S = ai2;
ai2 op(ai2 a, ai2 b) { return {min(a[0], b[0]), max(a[1], b[1])}; }
ai2 e() { return {INT_MAX, INT_MIN}; }
using F = ai2;
ai2 mapping(ai2 x, ai2 a, int c) { return {a[0] + x[0], a[1] + x[1]}; }
ai2 composition(ai2 x, ai2 y) { return {x[0] + y[0], x[1] + y[1]}; }
ai2 id() { return {0, 0}; }

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

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    set<int> oo, cc;
    auto rem = [&](int i) {
        if (i and s[i - 1] == s[i])
            s[i] == ')' ? cc.erase(i - 1) : oo.erase(i - 1);
        if (i + 1 < n and s[i] == s[i + 1])
            s[i] == ')' ? cc.erase(i) : oo.erase(i);
    };

    auto add = [&](int i) {
        if (i and s[i - 1] == s[i])
            s[i] == ')' ? cc.insert(i - 1) : oo.insert(i - 1);
        if (i + 1 < n and s[i] == s[i + 1])
            s[i] == ')' ? cc.insert(i) : oo.insert(i);
    };

    for (int i = 0; i < n; i++)
        add(i);

    v<ai2> d(n);
    for (int i = 0; i < n; i++) {
        d[i][0] = i ? d[i - 1][0] : 0;
        d[i][0] += s[i] == ')' ? -1 : 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        d[i][1] = i + 1 < n ? d[i + 1][1] : 0;
        d[i][1] += s[i] == ')' ? -1 : 1;
    }
    lazy_segtree seggy(d);

    while (q--) {
        int i; cin >> i; i--;
        rem(i);
        if (s[i] == ')') {
            seggy.apply(i, n, {2, 0});
            seggy.apply(0, i + 1, {0, 2});
            s[i] = '(';
        }
        else {
            seggy.apply(i, n, {- 2, 0});
            seggy.apply(0, i + 1, {0, - 2});
            s[i] = ')';
        }
        add(i);

        bool ok = 1;
        {
            int lo = 0, hi = n - 1, lb = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (seggy.prod(0, mid + 1)[0] < 0)
                    lb = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
            if (lb != n and (oo.empty() or *oo.begin() > lb))
                ok = 0;
        }
        {
            int lo = 0, hi = n - 1, rb = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (seggy.prod(mid, n)[1] > 0)
                    rb = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            if (rb != -1 and (cc.empty() or *cc.rbegin() < rb))
                ok = 0;
        }

        ok &= (abs(seggy.get(n - 1)[0]) & 1) ^ 1;
        cout << (ok ? "YES" : "NO") << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
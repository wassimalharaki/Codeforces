#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) { return max(a, b); }
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
    int n, k, d; cin >> n >> k >> d;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    v<int> lm(n), rm(n);
    int l = 0, r = 0;
    while (r < n) {
        while (a[r] - a[l] > d) l++;
        rm[r] = r - k + 1;
        lm[r++] = l;
    }

    segtree<int, op, e> seggy(n + 1);
    seggy.set(0, 1);
    for (int i = 0; i < n; i++)
        if (lm[i] <= rm[i])
            seggy.set(i + 1, seggy.prod(lm[i], rm[i] + 1));
    cout << (seggy.get(n) ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
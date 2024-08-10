#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 12;

using aiN = array<int, N>;

aiN op(aiN a, aiN b) {
    for (int i = 0; i < N; i++)
        a[i] += b[i];
    return a;
}

aiN e() {
    aiN x; x.fill(0);
    return x;
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
    int n, k; cin >> n >> k;
    ++k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    segtree<aiN, op, e> seggy(n + 1);
    for (int& x : a) {
        aiN y = seggy.prod(0, x);
        aiN me; me.fill(0); me[1]++;
        for (int i = 2; i < N; i++)
            me[i] += y[i - 1];
        seggy.set(x, me);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += seggy.get(i)[k];
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
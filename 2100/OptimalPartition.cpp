#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return INT_MIN;
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

int get(int x) {
    return (x ? x / abs(x) : 0);
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> pref(n + 1);
    partial_sum(a.begin(), a.end(), pref.begin() + 1);

    v<int> coord(pref);
    sort(coord.begin(), coord.end());
    coord.resize(unique(coord.begin(), coord.end()) - coord.begin());

    auto id = [&](int x) {
        return lower_bound(coord.begin(), coord.end(), x) - coord.begin();
    };

    segtree<int, op, e> seggy(n + 1);
    seggy.set(id(0), 0);

    v<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + get(a[i]);

        int j = id(pref[i + 1]);
        dp[i + 1] = max(dp[i + 1], i + 1 + seggy.prod(0, j));
        seggy.set(j, max(seggy.get(j), dp[i + 1] - (i + 1)));
    }
    cout << dp[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
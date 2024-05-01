#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

array<int, 2> op(array<int, 2>& a, array<int, 2>& b) {
    if (a[1])
        return {a[0] ^ b[0], 0};
    else
        return {a[0] | b[0], 1};
}

array<int, 2> e() {
    return {0, 0};
}

// O(nlog(n)), O(log(n))
template <class S, S (*op)(S&, S&), S (*e)()>
struct segtree {
    int n, size, log;
    vector<S> d;

    segtree(int n) : segtree(vector<S>(n, e())) {}
    
    segtree(const vector<S>& nums) {
        n = nums.size();
        size = bit_ceil(n);
        log = __builtin_ctz(size);
        d = vector<S>(size << 1, e());
        for (int i = 0; i < n; i++) d[size + i] = nums[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    void update(int k) { d[k] = op(d[k << 1], d[(k << 1) + 1]); }

    int bit_ceil(int n) {
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

    v<array<int, 2>> nums(1 << n);
    for (auto& a : nums) cin >> a[0];
    segtree<array<int, 2>, op, e> seggy(nums);

    while (m--) {
        int p, b; cin >> p >> b;
        seggy.set(p - 1, {b, 0});
        cout << seggy.all_prod()[0] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
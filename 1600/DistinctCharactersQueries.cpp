#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

using ai26 = array<int, 26>;

ai26 op(const ai26& a, const ai26& b) {
    ai26 x;
    for (int i = 0; i < 26; i++)
        x[i] = a[i] + b[i];
    return x;
}

ai26 e() {
    ai26 x;
    for (int i = 0; i < 26; i++)
        x[i] = 0;
    return x;
}

template <class S, S (*op)(const S&, const S&), S (*e)()>
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
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();

    v<ai26> nums(n, e());
    for (int i = 0; i < n; i++)
        nums[i][s[i] - 'a'] = 1;
    segtree<ai26, op, e> seggy(nums);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int p; cin >> p;
            char c; cin >> c;
            ai26 x = e();
            x[c - 'a'] = 1;
            seggy.set(p - 1, x);
        }
        else {
            int l, r; cin >> l >> r;
            ai26 x = seggy.prod(l - 1, r);
            int y = 0;
            for (int i = 0; i < 26; i++)
                if (x[i] > 0)
                    y++;
            cout << y << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
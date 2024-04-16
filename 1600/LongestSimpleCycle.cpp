#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return 0;
}

template <class S, S (*op)(S, S), S (*e)()>
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
    int n; cin >> n;

    v<int> a(n), b(n), c(n), d(n), x(n);
    for (int& x : c) cin >> x;
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int i = 0; i < n; i++)
        if (a[i] > b[i])
            swap(a[i], b[i]);

    for (int i = n - 2; i >= 0; i--)
        d[i] = d[i + 1] + a[i + 1] + c[i] - b[i + 1] + 1;

    for (int i = 0; i < n; i++)
        x[i] = b[i] - a[i] + 1 + d[i];

    int ans = 0;
    segtree<int, op, e> seggy(x);
    v<int> bad;
    for (int i = 1; i < n; i++)
        if (a[i] == b[i])
            bad.push_back(i);

    for (int i = n - 1; i >= 0; i--)
        if (bad.empty())
            ans = max(ans, c[i] - d[i] + seggy.prod(1, i + 1));
        else {
            auto it = upper_bound(all(bad), i);
            if (it == bad.begin())
                ans = max(ans, c[i] - d[i] + seggy.prod(1, i + 1));
            else {
                --it;
                ans = max(ans, c[i] - d[i] + seggy.prod(*it, i + 1));
            }
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
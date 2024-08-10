#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return a + b;
}

int e() {
    return 0;
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

    v<int> a(n), c(n), pos(n);
    v<array<int, 2>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    for (int i = 0; i < n / 2; i++)
        b[i][0] += i + 1, b[n - i - 1][0] += i + 1;
    if (n & 1) b[n / 2][0] += (n + 1) / 2;
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++)
        c[i] = b[i][0], pos[b[i][1]] = i;
    segtree<int, op, e> seggy(c);

    auto walk = [&](int x) -> int {
        if (seggy.prod(0, n) <= x)
            return n;
        int i = 1;
        while (i < seggy.size)
            if (seggy.d[i << 1] > x)
                i <<= 1;
            else
                x -= seggy.d[i << 1],
                i = (i << 1) + 1;
        return i - seggy.size;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] + i + 1 > k) continue;
        int prev = seggy.get(pos[i]);
        seggy.set(pos[i], 0);
        int j = walk(k - (a[i] + i + 1));
        ans = max(ans, 1 + j - (pos[i] < j));
        seggy.set(pos[i], prev);
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
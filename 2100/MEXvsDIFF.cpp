#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

//{frequency, alive}
using ai2 = array<int, 2>;
ai2 op(ai2 a, ai2 b) {
    return {a[0] + b[0], a[1] + b[1]};
}
ai2 e() { return {0, 0}; }

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
    int n, k; cin >> n >> k;

    map<int, int> cnt;
    v<int> have(n + 1), idx(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= n) have[x] = 1;
        cnt[x]++;
    }

    v<array<int, 2>> a{e()};
    {
        v<array<int, 2>> b;
        for (auto& [x, y] : cnt)
            b.push_back({y, x});
        sort(b.begin(), b.end());
        for (int i = 0; i < (int) b.size(); i++) {
            a.push_back({b[i][0], 1});
            if (b[i][1] <= n)
                idx[b[i][1]] = i + 1;
        }
    }

    segtree<ai2, op, e> seggy(a);
    int ans = 1e9, gaps = 0;
    for (int i = 0; i <= n; i++) {
        if (gaps > k) break;

        int rem = 0, curr = 0, rt = 1;
        while (rt < seggy.size)
            if (curr + seggy.d[rt << 1][0] <= k) {
                curr += seggy.d[rt << 1][0];
                rem += seggy.d[rt << 1][1];
                rt = (rt << 1) + 1;
            }
            else rt <<= 1;
        if (seggy.d[1][0] <= k) rem = seggy.d[1][1];

        ans = min(ans, seggy.all_prod()[1] - rem);
        if (not have[i])
            gaps++;
        else
            seggy.set(idx[i], e());
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
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return min(a, b);
}

int e() {
    return 1e9;
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
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> big(n), small(n);
    stack<int> inc, dec;
    for (int i = 0; i < n; i++) {
        while (inc.size() and a[inc.top()] < a[i])
            inc.pop();
        while (dec.size() and a[dec.top()] > a[i])
            dec.pop();

        if (inc.size())
            big[inc.top()].push_back(i);
        if (dec.size())
            small[dec.top()].push_back(i);
        inc.push(i); dec.push(i);
    }

    inc = dec = stack<int>();
    v<int> first_small(n, n), first_big(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (inc.size() and a[inc.top()] < a[i])
            inc.pop();
        while (dec.size() and a[dec.top()] > a[i])
            dec.pop();
        
        if (inc.size())
            first_big[i] = inc.top();
        if (dec.size())
            first_small[i] = dec.top();
        inc.push(i); dec.push(i);
    }

    segtree<int, op, e> min_tree(n), max_tree(n);
    v<int> dp(n, 1e9); dp[n - 1] = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (big[i].size()) {
            max_tree.set(big[i].back(), e());
            big[i].pop_back();
        }
        while (small[i].size()) {
            min_tree.set(small[i].back(), e());
            small[i].pop_back();
        }

        dp[i] = min({
            dp[i],
            1 + min_tree.prod(i, first_big[i]),
            1 + max_tree.prod(i, first_small[i])
        });

        min_tree.set(i, dp[i]);
        max_tree.set(i, dp[i]);
    }
    cout << dp[0] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
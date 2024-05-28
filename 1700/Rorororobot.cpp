#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

// O(nlog(n)), O(1)
template <class S, S (*op)(S, S)>
struct sparse_table {
    v<v<S>> d;

    sparse_table(v<S>& a) {
        int n = a.size(), k = 64 - __builtin_clzll(n);
        d = v<v<S>>(k, v<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

using ai2 = array<int, 2>;

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(m);
    for (int& x : a) cin >> x;
    sparse_table<int, [](int a, int b) {return max(a, b);}> tbl(a);

    int q; cin >> q;
    while (q--) {
        ai2 x, y;
        cin >> x[0] >> x[1] >> y[0] >> y[1];
        int k; cin >> k;
        
        if (abs(x[0] - y[0]) % k or abs(x[1] - y[1]) % k) {
            cout << "NO" << nl;
            continue;
        }

        x[0] += (n - x[0]) / k * k;
        if (x[1] > y[1]) swap(x[1], y[1]);
        int max = tbl.prod(x[1] - 1, y[1]);
        cout << (max >= x[0] ? "NO" : "YES") << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
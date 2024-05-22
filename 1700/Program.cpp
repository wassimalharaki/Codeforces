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

int op_min(int a, int b) {
    return min(a, b);
}

int op_max(int a, int b) {
    return max(a, b);
}

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
        if (l == r) return 0;
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    v<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + (s[i] == '+' ? 1 : -1);
    
    sparse_table<int, op_max> max_table(pref);
    sparse_table<int, op_min> min_table(pref);

    while (m--) {
        int l, r; cin >> l >> r; l--;
        int lb = 0, rb = 0;
        lb = min(lb, min_table.prod(0, l));
        rb = max(rb, max_table.prod(0, l));
        int x = pref[r] - pref[l];
        lb = min(lb, min_table.prod(r, n + 1) - x);
        rb = max(rb, max_table.prod(r, n + 1) - x);
        cout << rb - lb + 1 << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
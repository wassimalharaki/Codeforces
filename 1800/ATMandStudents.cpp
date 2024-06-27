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

int op(int a, int b) {
    return min(a, b);
}

int e() {
    return 1e9;
}

// O(nlog(n)), O(1)
template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
    vector<vector<S>> d;

    sparse_table(vector<S>& a) {
        int n = a.size(), k = 64 - __builtin_clzll(n);
        d.resize(k, vector<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        if (l == r) return e();
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    int n, s; cin >> n >> s;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> pref(n);
    partial_sum(a.begin(), a.end(), pref.begin());
    sparse_table<int, op, e> min_table(pref);

    int ans = 0, l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n, x = i ? pref[i - 1] : 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (min_table.prod(i, mid) < x - s)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        if (hi - i > ans) {
            ans = hi - i;
            l = i + 1, r = hi;
        }
    }
    if (ans == 0)
        cout << -1 << nl;
    else
        cout << l << " " << r << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
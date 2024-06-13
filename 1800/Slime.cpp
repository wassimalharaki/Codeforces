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
    return 0;
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

/*
m m p m p m ||| m p p m p
*/

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    auto b = a;
    for (int& x : b) x = abs(x);

    v<int> pref(n + 1);
    partial_sum(b.begin(), b.end(), pref.begin() + 1);
    sparse_table<int, op, e> min_table(a);

    int ans = max(
        a[0] + pref[n] - pref[1] - 2 * max(0ll, min_table.prod(1, n)),
        a[n - 1] + pref[n - 1] - 2 * max(0ll, min_table.prod(0, n - 1))
    );

    for (int i = 1; i < n - 1; i++)
        ans = max(
            ans,
            a[i] + pref[i] + pref[n] - pref[i + 1]
                - 2 * max(0ll, min_table.prod(0, i))
                - 2 * max(0ll, min_table.prod(i + 1, n))
        );
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
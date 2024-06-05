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

using S = int;

int op(int a, int b) {
    return __gcd(a, b);
}

// O(nlog(n)), O(1)
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
        if (l == r) return 1e9;
        int i = 63 - __builtin_clzll(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    if (n == 1) {
        cout << 1 << nl;
        return;
    }

    v<int> b(n - 1);
    for (int i = 0; i < n - 1; i++)
        b[i] = abs(a[i + 1] - a[i]);
    sparse_table ok(b);

    int l = 0, r = 0, ans = 1;
    while (r < n)
        if (ok.prod(l, r) > 1)
            ans = max(ans, r++ - l + 1);
        else l++;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
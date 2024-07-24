#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return __gcd(a, b);
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

void solve() {
    int n; cin >> n;

    int g = 0;
    v<int> a(n);
    for (int& x : a)
        cin >> x, g = op(g, x);
    for (int i = 0; i < n; i++)
        a.push_back(a[i]);

    sparse_table<int, op, e> gcd_table(a);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = 2 * n, x = 2 * n;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (gcd_table.prod(i, mid) == g)
                x = mid - i - 1, r = mid - 1;
            else
                l = mid + 1;
        }
        ans = max(ans, x);
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) {
    return gcd(a, b);
}

int e() {
    return 0;
}

// O(nlog(n)), O(1)
template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
    vector<vector<S>> d;

    sparse_table(vector<S>& a) {
        int n = a.size(), k = 1 + (n ? __lg(n) : 0);
        d.resize(k, vector<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        if (l == r) return e();
        int i = __lg(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sparse_table<int, op, e> g(a);

    map<int, int> ok;
    for (int i = 0; i < n; i++) {
        int x = a[i], l = i, r = i;
        while (1) {
            int lo = 0, hi = l;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                
                if (g.prod(mid, i + 1) == x)
                    hi = mid - 1, l = mid;
                else
                    lo = mid + 1;
            }
            ok[x] += r - l + 1;
            if (l-- == 0) break;
            r = l;
            x = gcd(x, a[l]);
        }
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << ok[x] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
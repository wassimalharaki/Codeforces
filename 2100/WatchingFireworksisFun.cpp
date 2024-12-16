#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int op(int a, int b) { return max(a, b); }
int e() { return LLONG_MIN; }

// O(nlog(n)), O(1)
template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
    vector<vector<S>> d;

    sparse_table(const vector<S>& a) {
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

void rebuild(v<v<int>>& d, v<int>& a) {
    int n = a.size(), k = 1 + (n ? __lg(n) : 0);
    copy(a.begin(), a.end(), d[0].begin());
    
    for (int i = 1; i <= k; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
}

void solve() {
    int n, m, d; cin >> n >> m >> d;

    v<int> a(m), b(m), t(m);
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i] >> t[i];
    
    int prev = 1;
    v<int> dp(n + 1), ndp(n + 1);
    sparse_table<int, op, e> st(dp);
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            int l = max(1ll, j - (t[i] - prev) * d);
            int r = min(n, j + (t[i] - prev) * d);
            ndp[j] = st.prod(l, r + 1) + b[i] - abs(a[i] - j);
        }
        prev = t[i];
        rebuild(st.d, ndp);
        dp.swap(ndp);
    }
    cout << *max_element(dp.begin() + 1, dp.end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
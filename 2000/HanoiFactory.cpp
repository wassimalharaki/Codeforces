#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai3 = array<int, 3>;
ai3 op(ai3 a, ai3 b) { return a[1] < b[1] ? a : b; }
ai3 e() { return {0, 0, 0}; }

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

void solve() {
    int n; cin >> n;

    v<ai3> a(n);
    for (auto& [b, _a, h] : a)
        cin >> _a >> b >> h;
    a.push_back({INT_MAX, 0, 0});
    sort(a.rbegin(), a.rend());
    sparse_table<ai3, op, e> min_table(a);

    v<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int lo = 0, hi = i - 1, l = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (min_table.prod(mid, i)[1] < a[i][0])
                lo = mid + 1, l = mid;
            else
                hi = mid - 1;
        }
        dp[i] = dp[l] + a[i][2];
    }
    cout << *max_element(dp.begin(), dp.end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> a(n, v<int>(m));
    for (auto& x : a) {
        string s; cin >> s;
        for (int i = 0; i < m; i++)
            x[i] = s[i] - '0';
    }

    if (m < n) {
        v<v<int>> b(m, v<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[j][i] = a[i][j];
        swap(a, b); swap(n, m);
    }

    if (n >= 4 and m >= 4) {
        cout << -1 << nl;
        return;
    }

    if (n == 1 or m == 1) {
        cout << 0 << nl;
        return;
    }

    auto get = [&](int j, int mask) -> int {
        int x = 0;
        for (int i = 0; i < n; i++)
            x += ((a[i][j] << i) ^ (mask & (1 << i))) > 0;
        return x;
    };

    auto valid = [&](int j, int k) -> bool {
        for (int i = 0; i < n - 1; i++) {
            int cnt = 0;
            for (int l = i; l < i + 2; l++)
                cnt += ((j & (1 << l)) > 0) + ((k & (1 << l)) > 0);
            if (cnt & 1 ^ 1) return 0;
        }
        return 1;
    };

    const int N = 1 << n;
    v<v<int>> dp(m + 1, v<int>(N, INT_MAX));
    fill(dp[0].begin(), dp[0].end(), 0ll);
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (valid(j, k))
                    dp[i][k] = min(dp[i][k], get(i - 1, k) + dp[i - 1][j]);
    cout << *min_element(dp[m].begin(), dp[m].end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
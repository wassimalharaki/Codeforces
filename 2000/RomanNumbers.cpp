#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 10;

void solve() {
    string s; cin >> s;
    int n = s.size(), m; cin >> m;

    v<int> a(n), pw(n), fact(n + 1), cnt(N);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        cnt[a[i]]++;
        pw[i] = i ? 10 * pw[i - 1] : 1;
        fact[i] = i ? i * fact[i - 1] : 1;
    }
    fact[n] = n * fact[n - 1];

    v dp(1 << n, v<int>(m)); dp[0][0] = 1;
    for (int mask = 1, sz = 1; mask < (1 << n); sz = __builtin_popcountll(++mask))
        for (int i = 0; i < n; i++)
            if (((1 << i) & mask) and (a[i] or mask + 1 != (1 << n)))
                for (int j = 0; j < m; j++)
                    dp[mask][(a[i] * pw[sz - 1] + j) % m]
                        += dp[mask ^ (1 << i)][j];
    int ans = dp.back()[0];
    for (int i = 0; i < N; i++)
        ans /= fact[cnt[i]];
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
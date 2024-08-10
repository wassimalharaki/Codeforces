#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void add(int& a, int b, const int mod) {
    a = (int64_t(a) + b) % mod;
}

void solve() {
    int n, m; cin >> n >> m;
    const int mod = m;

    v<int> dp(n + 1), diff(n + 1);
    int sum = 0, curr = 0; dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        add(curr, diff[i], mod);
        add(dp[i], sum + curr, mod);
        add(sum, dp[i], mod);
        for (int j = i * 2; j <= n; j += i) {
            add(diff[j], dp[i], mod);
            if (j + j / i <= n)
                add(diff[j + j / i], - dp[i], mod);
        }
    }
    add(dp[n], mod, mod);
    cout << dp[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
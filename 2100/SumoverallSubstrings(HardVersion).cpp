#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    v<int> dp(n);
    dp[0] = (s[0] == '1');
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            dp[i] = dp[i - 1];
            continue;
        }
        dp[i] = 1 + min(2ll, i);
        if (i - 3 >= 0)
            dp[i] += dp[i - 3] + i - 2;
    }
    cout << accumulate(dp.begin(), dp.end(), 0ll) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
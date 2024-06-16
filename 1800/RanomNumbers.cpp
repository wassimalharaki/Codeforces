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

v<int> val;

void solve() {
    string s; cin >> s;
    int n = s.size();

    v dp(n + 1, v<int>(5));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 5; j++)
            dp[i][j] = dp[i - 1][max(j, (int) s[i - 1] - 'A')]
                + (s[i - 1] >= 'A' + j ? val[s[i - 1]] : -val[s[i - 1]]);

    int ans = -1e9, curr = 0;
    char prev = 'A';
    for (int i = n - 1; i >= 0; i--) {
        for (int j = prev - 'A'; j < 5; j++)
            ans = max(ans, curr + val[j + 'A'] + dp[i][j]);
        if (s[i] >= prev)
            prev = s[i], curr += val[s[i]];
        else
            curr -= val[s[i]];
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    val.resize((int) 'E' + 1, 1);
    for (int i = 1; i < 5; i++)
        val[i + 'A'] = val[i + 'A' - 1] * 10;

    int T = 1;
    cin >> T;
    while (T--) solve();
}
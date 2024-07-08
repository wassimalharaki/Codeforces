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

void solve() {
    string s; cin >> s;
    int n = s.size();

    int ans = 0, cnt = 1;
    v<int> dp(n);
    for (int i = 1; i < n; i++)
        if (s[i] == ')') {
            if (s[i - 1] == ')') {
                int j = i - dp[i - 1] - 1;
                if (j >= 0 and s[j] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (j - 1 >= 0)
                        dp[i] += dp[j - 1];
                }
            }
            else {
                dp[i] = 2;
                int j = i - 2;
                if (j >= 0) dp[i] += dp[j];
            }
            if (dp[i] > ans)
                ans = dp[i], cnt = 1;
            else if (dp[i] == ans)
                cnt++;
        }
    
    if (ans == 0) cnt = 1;
    cout << ans << " " << cnt << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
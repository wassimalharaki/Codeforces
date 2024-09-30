#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 5e5 + 1;

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n), rm(n), dp(n), prev(N, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        rm[i] = prev[a[i]];
        prev[a[i]] = i;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == k)
            dp[i] = ++cnt;
        else if (rm[i] == -1)
            dp[i] = 1 + cnt;
        else
            dp[i] = 1 + max(cnt, dp[rm[i]]);
    
    int ans = cnt; cnt = 0;
    for (int i = n - 1; i >= 0; i--)
        if (a[i] == k)
            cnt++;
        else
            ans = max(ans, dp[i] + cnt);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
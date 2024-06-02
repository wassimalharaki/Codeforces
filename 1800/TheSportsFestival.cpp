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

int bruteforce(v<int> a) {
    int n = a.size(), ans = LLONG_MAX;
    do {
        int mn = 1e9, mx = -1e9, curr = 0;
        for (int& x : a) {
            mn = min(mn, x);
            mx = max(mx, x);
            curr += mx - mn;
        }
        ans = min(ans, curr);
    } while (next_permutation(a.begin(), a.end()));
    return ans;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    
    v<array<int, 2>> b{{a[0], 1}};
    for (int i = 1; i < n; i++)
        if (a[i] == b.back()[0])
            b.back()[1]++;
        else
            b.push_back({a[i], 1});
    n = b.size();

    v<v<int>> dp(n, v<int>(n, 1e15));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    
    for (int i = 1; i < n; i++)
        for (int j = 0; j + i < n; j++)
            dp[j][j + i] = min(
                dp[j][j + i - 1] + (b[j + i][0] - b[j][0]) * b[j + i][1],
                dp[j + 1][j + i] + (b[j + i][0] - b[j][0]) * b[j][1]
            );
    cout << dp[0][n - 1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
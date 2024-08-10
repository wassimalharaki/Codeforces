#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int mxN = 1e6;

void solve() {
    int n; cin >> n;

    v<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    v<array<int, 3>> dp(n + 1, {mxN, -1, -1});
    dp[n] = {0, -1, -1};
    int mxL = n;
    queue<int> q;
    q.push(n);
    for (int i = q.front(); q.size();) {
        for (int j = mxL - 1; j >= i - a[i]; j--)
            if (dp[j + b[j]][0] > dp[i][0] + 1) {
                dp[j + b[j]] = {dp[i][0] + 1, j, i};
                q.push(j + b[j]);
            }
        mxL = min(mxL, i - a[i]);
        q.pop();
        if (q.size()) i = q.front();
    }
    if (dp[0][0] == mxN)
        cout << -1 << nl;
    else {
        cout << dp[0][0] << nl;
        v<int> ans;
        for (int i = 0, u = 0; i < dp[0][0]; i++, u = dp[u][2])
            ans.push_back(dp[u][1]);
        reverse(ans.begin(), ans.end());
        for (int& x : ans)
            cout << x << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
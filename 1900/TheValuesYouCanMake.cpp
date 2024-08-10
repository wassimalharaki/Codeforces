#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 501;

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v dp(k + 1, bitset<N>());
    dp[0][0] = 1;
    for (int& x : a)
        if (x <= k)
            for (int i = k - 1; i >= 0; i--)
                if (i + x <= k and dp[i].count())
                    dp[i + x] |= dp[i] | (dp[i] << x);

    cout << dp[k].count() << nl;
    for (int i = 0; i < N; i++)
        if (dp[k][i])
            cout << i << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
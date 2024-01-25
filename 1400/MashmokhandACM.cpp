#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

const int mod = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;

    vvi dp(n + 1, vi(k + 1, 1));
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i][j - 1];
            for (int m = 2 * i; m <= n; m += i)
                dp[i][j] = (dp[i][j] + dp[m][j - 1]) % mod;
        }
    cout << dp[1][k];
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
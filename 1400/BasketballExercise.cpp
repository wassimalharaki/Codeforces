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

void solve() {
    int n; cin >> n;

    vvi nums(2, vi(n));
    for (vi& a : nums)
        for (int& b : a)
            cin >> b;
    
    vvi dp(2, vi(n + 2));
    for (int i = 2; i < n + 2; i++) {
        dp[0][i] = nums[0][i - 2] + max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = nums[1][i - 2] + max(dp[0][i - 1], dp[0][i - 2]);
    }
    cout << max(dp[0][n + 1], dp[1][n + 1]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
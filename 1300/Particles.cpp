#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
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

    vi nums(n);
    for (int& a : nums) cin >> a;

    vi dp(n);
    int odd = -INT_MAX, even = -INT_MAX;
    for (int i = 0; i < n; i++) {
        dp[i] = max({(i & 1 ? odd : even) + nums[i], nums[i]});
        i & 1 ? odd = max(odd, dp[i]) : even = max(even, dp[i]);
    }
    cout << *max_element(all(dp)) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
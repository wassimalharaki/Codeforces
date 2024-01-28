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
    int n, m, d; cin >> n >> m >> d;
    n *= m;

    vi nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));

    int g = 0;
    for (int& a : nums)
        g = __gcd(g, a - nums[0]);
    
    if (g % d) {
        cout << -1 << nl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(nums[i] - nums[n / 2]) / d;
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
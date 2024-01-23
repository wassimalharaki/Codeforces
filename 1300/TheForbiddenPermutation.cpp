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

    vi pos(n + 1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        pos[a] = i + 1;
    }

    vi nums(m);
    for (int& a : nums) cin >> a;

    int ans = INF;
    for (int i = 0; i < m - 1; i++) {
        int l = pos[nums[i]], r = pos[nums[i + 1]];
        if (r < l or r > l + d) {
            ans = 0;
            break;
        }
        if (d < n - 1)
            ans = min(ans, d - (r - l) + 1);
        ans = min(ans, r - l);
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
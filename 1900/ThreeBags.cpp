#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    array<int, 3> sum; sum.fill(0);
    array<int, 3> min; min.fill(LLONG_MAX);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum[0] += x;
        min[0] = std::min(min[0], x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        sum[1] += x;
        min[1] = std::min(min[1], x);
    }
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        sum[2] += x;
        min[2] = std::min(min[2], x);
    }
    sort(min.begin(), min.end());

    int ans = sum[0] + sum[1] + sum[2] - 2 * (min[0] + min[1]);
    ans = max(ans, sum[1] + sum[2] - sum[0]);
    ans = max(ans, sum[0] + sum[2] - sum[1]);
    ans = max(ans, sum[0] + sum[1] - sum[2]);

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
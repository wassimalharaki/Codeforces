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
    int n, m; cin >> n >> m;

    vvi nums(n, vi(m));
    for (vi& a : nums)
        for (int& b : a)
            cin >> b;
    
    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++)
        for (int j = 0; j < (m + 1) / 2; j++) {
            vi ok {
                nums[i][j],
                nums[i][m - j - 1],
                nums[n - i - 1][j],
                nums[n - i - 1][m - j - 1]
            };
            sort(all(ok));
            int sum = 0;
            for (int k = 0; k < 4; k++)
                sum += abs(ok[1] - ok[k]);
            ans += (i == n / 2 or j == m / 2 ? sum / 2 : sum);
        }
    cout << ans nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
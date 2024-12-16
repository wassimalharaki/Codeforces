#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 1e9 + 7;
void add(int& a, int b) { a = (a + b % mod + mod) % mod; }

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    v<int> pref(n + 1);
    partial_sum(a.begin(), a.end(), pref.begin() + 1);

    v dp(n + 1, v<array<int, 2>>(m + 1, {(int) 1e18, 0}));
    v dpref(n + 1, v<int>(m + 1));
    for (int j = 0; j <= m; j++) {
        dp[0][j] = {0, 1};
        dpref[0][j] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            add(dpref[i][j], dpref[i - 1][j]);
            dp[i][j] = dp[i][j - 1];

            int l = i - 1;
            {
                int lo = 0, hi = i - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (pref[i] - pref[mid] <= b[j - 1])
                        hi = mid - 1, l = mid;
                    else
                        lo = mid + 1;
                }
            }

            if (pref[i] - pref[l] > b[j - 1]) {
                add(dpref[i][j], dp[i][j][1]);
                continue;   
            }

            if (m - j + dp[l][j][0] > dp[i][j][0]) {
                add(dpref[i][j], dp[i][j][1]);
                continue;   
            }

            if (m - j + dp[l][j][0] < dp[i][j][0]) {
                dp[i][j][0] = m - j + dp[l][j][0];
                dp[i][j][1] = 0;
            }

            int ub = l;
            {
                int lo = l, hi = i - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (m - j + dp[mid][j][0] == dp[i][j][0])
                        ub = mid, lo = mid + 1;
                    else
                        hi = mid - 1;
                }
            }

            add(dp[i][j][1], dpref[ub][j] - (l ? dpref[l - 1][j] : 0));
            add(dpref[i][j], dp[i][j][1]);
        }
    }

    if (dp[n][m][0] == 1e18)
        cout << -1 << nl;
    else
        cout << dp[n][m][0] << " " << dp[n][m][1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
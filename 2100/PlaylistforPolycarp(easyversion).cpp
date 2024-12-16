#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 15;
const int M = 226;
const int K = 3;
const int mod = 1e9 + 7;

int dp[1 << N][M][K];

void add(int& a, int b) { a = (a + b) % mod; }

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 2>> a(n);
    for (auto& [x, y] : a)
        cin >> x >> y, y--;
    
    for (int i = 0; i < K; i++)
        dp[0][0][i] = 1;

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                for (int j = 0; j < M; j++) {
                    for (int k = 0; k < K; k++) {
                        if (a[i][1] != k and a[i][0] + j < M) {
                            add(dp[mask][j + a[i][0]][a[i][1]],
                                dp[mask ^ (1 << i)][j][k]);
                        }
                    }
                }
            }
        }
        for (int k = 0; k < K; k++) {
            add(ans, dp[mask][m][k]);
        }
    }
    cout << ans * (mod + 1) / 2 % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, 0, sizeof(dp));
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
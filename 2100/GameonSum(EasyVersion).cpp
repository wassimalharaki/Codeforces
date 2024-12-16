#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 2001;
const int mod = 1e9 + 7;
const int minv2 = (mod + 1) / 2;
int dp[N][N];

int f(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) return dp[i][j] = 0;
    if (j == 0) return dp[i][j] = i;
    int x = (f(i - 1, j - 1) - f(i - 1, j) + mod) * minv2 % mod;
    return dp[i][j] = (x + f(i - 1, j)) % mod;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    cout << f(n, n - m) * k % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    int T = 1;
    cin >> T;
    while (T--) solve();
}
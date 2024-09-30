#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;
const int N = 301;
const int zero = N * N;
const int M = 2 * zero;

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> dp(M), ndp(M);
    dp[a[1] + zero] = 1;
    for (int i = 2; i < n; i++) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int j = 0; j < M; j++)
            if (dp[j]) {
                add(ndp[a[i] + (j - zero) + zero], dp[j]);
                add(ndp[a[i] - (j - zero) + zero], dp[j]);
            }
        add(ndp[a[i] + zero], - dp[zero]);
        dp.swap(ndp);
    }
    int ans = 0;
    for (int& x : dp)
        add(ans, x);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
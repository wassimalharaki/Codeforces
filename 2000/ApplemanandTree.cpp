#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 1e9 + 7;

// O(log(min(a, b)))
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1;
    while (b) {
        int q = a / b;
        tie(x, x1) = make_pair(x1, x - q * x1);
        tie(y, y1) = make_pair(y1, y - q * y1);
        tie(a, b) = make_pair(b, a - q * b);
    }
    return a;
}

// O(log(min(a, b)))
int modinv(int a, const int m = mod) {
    int x, y;
    int g = gcd(a, m, x, y);
    return (g == 1 ? (x % m + m) % m : 0);
}

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
    }

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<array<int, 2>> dp(n);
    for (int u = n - 1; u >= 0; u--) {
        if (a[u]) {
            dp[u][1] = 1;
            for (int& i : adj[u])
                dp[u][1] = dp[u][1] * (dp[i][1] + dp[i][0]) % mod;
        }
        else {
            int x = 1;
            for (int& i : adj[u]) {
                x = x * (dp[i][0] + dp[i][1]) % mod;
                dp[u][0] = dp[u][0] * dp[i][1] % mod;
            }
            dp[u][0] = x;

            for (int& i : adj[u])
                dp[u][1] = (dp[u][1] + x * dp[i][1] % mod
                         * modinv(dp[i][0] + dp[i][1]) % mod) % mod;
        }
    }
    cout << dp[0][1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

const int N = 2e5 + 1;
const int mod = 1e9 + 7;
int fact[N];

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

// O(log(a))
int modinv(int a) {
    int x, y;
    int g = gcd(a, mod, x, y);
    return (g == 1 ? (x % mod + mod) % mod : 0);
}

// O(log(max((n - r)! % mod, r! % mod)))
int choose(int n, int r) {
    return fact[n] * modinv(fact[n - r] * fact[r] % mod) % mod;
}

// O(N)
void build() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = i * fact[i - 1] % mod;
}

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n, k; cin >> n >> k;

    if (k == 0) {
        cout << 1 << nl;
        return;
    }

    int x = n & 1, y = 0;
    for (int i = 0; i < n; i += 2)
        add(x, choose(n, i));
    for (int i = 1; i < n; i += 2)
        add(y, choose(n, i));

    v<array<int, 3>> dp(k + 1);
    dp[0] = {1, 0, 0};
    for (int i = 1; i <= k; i++) {
        dp[i][0] = dp[i - 1][0] * x % mod;
        dp[i][1] = x * dp[i - 1][1] % mod;
        add(dp[i][1], y * (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]));
        dp[i][2] = x * dp[i - 1][2] % mod;
        add(dp[i][2], (n & 1 ^ 1) * (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]));
    }
    cout << (dp[k][0] + dp[k][2]) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    cin >> T;
    while (T--) solve();
}
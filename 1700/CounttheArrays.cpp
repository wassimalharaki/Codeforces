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
const int mod = 998244353;
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
    int n, m; cin >> n >> m;
    
    int x = 0;
    for (int i = 1; i < n - 1; i++)
        add(x, modinv(fact[i - 1] * fact[n - i - 2]));

    v<int> dp(m + 1);
    for (int i = n - 1; i <= m; i++)
        add(dp[i], dp[i - 1] + fact[i - 1] * modinv(fact[i + 1 - n]) % mod * x % mod);
    cout << dp[m] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
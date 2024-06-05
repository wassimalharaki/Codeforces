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

const int N = 1e6 + 1;
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

void add (int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int a, b, n; cin >> a >> b >> n;

    auto valid = [&](int x) -> bool {
        string s = to_string(x);
        for (char& c : s)
            if (c - '0' != a and c - '0' != b)
                return 0;
        return 1;
    };

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int x = i * a, y = (n - i) * b;
        if (not valid(x + y)) continue;
        add(ans, fact[n] * modinv(fact[i] * fact[n - i] % mod) % mod);
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;

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

v<int> thomas(v<int>& a, v<int>& b, v<int>& c, v<int>& d) {
    int n = a.size();
    v<int> x(n);
    for (int i = 1; i < n; i++) {
        int w = a[i] * modinv(b[i - 1]) % mod;
        b[i] = (b[i] - w * c[i - 1] % mod + mod) % mod;
        d[i] = (d[i] - w * d[i - 1] % mod + mod) % mod;
    }
    x[n - 1] = d[n - 1] * modinv(b[n - 1]) % mod;
    for (int i = n - 2; i >= 0; i--)
        x[i] = (d[i] - c[i] * x[i + 1] % mod + mod) * modinv(b[i]) % mod;
    return x;
}

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int x = 0;
    for (int i = 0; i < n; i++)
        x += s[i] != t[i];

    v<int> a(n + 1), b(n + 1, 1), c(n + 1), d(n + 1, 1);
    for (int i = 0; i <= n; i++) {
        a[i] = (- i + mod) * modinv(n) % mod;
        c[i] = (i - n + mod) * modinv(n) % mod;
        if (i == 0) a[i] = 0;
        if (i == n) c[i] = 0;
    }
    cout << thomas(a, b, c, d)[n - x] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
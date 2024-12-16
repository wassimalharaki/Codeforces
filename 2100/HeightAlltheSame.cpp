#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;

// O(log(b))
int binpow(int a, int b, const int m = mod) {
    a %= m;
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

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
    int n, m, l, r; cin >> n >> m >> l >> r;
    n *= m;

    if (l == r)
        return void(cout << 1 << nl);

    int o = (r - l) / 2 + ((l & 1) or (r & 1));
    int e = (r - l + 1) - o;
    o = o * modinv(e) % mod;

    int ans = 0;
    if (n & 1)
        ans = binpow(o + 1, n);
    else
        ans = (binpow(1 - o, n) + binpow(o + 1, n)) % mod * modinv(2) % mod;
    cout << ans * binpow(e, n) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
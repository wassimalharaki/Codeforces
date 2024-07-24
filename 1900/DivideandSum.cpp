#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 3e5 + 1;
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

void solve() {
    int n; cin >> n;
    n <<= 1;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    sort(a.rbegin(), a.rbegin() + n / 2);

    int x = 0;
    for (int i = 0; i < n / 2; i++)
        x += a[i + n / 2] - a[i];
    x %= mod;
    cout << x * choose(n, n / 2) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
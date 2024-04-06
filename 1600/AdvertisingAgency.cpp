#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

const int N = 1e3 + 1;
const int mod = 1e9 + 7;
int fact[N];

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

int modinv(int a) {
    int x, y;
    int g = gcd(a, mod, x, y);
    return (g == 1 ? (x % mod + mod) % mod : 0);
}

int choose(int n, int r) {
    return fact[n] * modinv(fact[n - r]) % mod * modinv(fact[r]) % mod;
}

void build() {
    memset(fact, 0, sizeof(fact));
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = i * fact[i - 1] % mod;
}

void solve() {
    int n, k; cin >> n >> k;

    map<int, int> ok;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ok[a]++;
    }

    int x = 0;
    for (auto it = ok.rbegin(); it != ok.rend(); it++) {
        int y = it -> second;
        if (x + y < k)
            x += y;
        else {
            cout << choose(y, k - x) << nl;
            break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    cin >> T;
    while (T--) solve();
}
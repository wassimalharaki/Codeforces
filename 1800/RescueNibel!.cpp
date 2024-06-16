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

void add(int& a, int b) {
    a += b;
    while (a >= mod) a -= mod;
}

void solve() {
    int n, k; cin >> n >> k;

    map<int, array<int, 2>> a;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[l][0]++, a[r][1]--;
    }

    int ans = 0, curr = 0;
    for (auto& [key, val] : a) {
        for (int i = 0; i < val[0]; i++)
            if (++curr >= k)
                add(ans, choose(curr - 1, k - 1));
        curr += val[1];
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
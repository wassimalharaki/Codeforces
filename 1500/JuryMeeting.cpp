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

v<int> fact(2e5 + 1);
const int mod = 998244353;

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

int modinv(int a, const int m = mod) {
    int x, y;
    int g = gcd(a, m, x, y);
    return (g == 1 ? (x % m + m) % m : 0);
}

int choose(int n, int r) {
    return fact[n] * modinv(fact[n - r]) % mod * modinv(fact[r]) % mod;
}

void solve() {
    int n; cin >> n;

    v<int> nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));

    if (nums[n - 1] - nums[n - 2] > 1) {
        cout << 0 << nl;
        return;
    }

    if (nums[n - 1] == nums[n - 2]) {
        cout << fact[n] << nl;
        return;
    }

    int x = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] != nums[n - 1] and nums[i] != nums[n - 2])
            x++;

    int ans = fact[n];
    for (int i = 0; i <= x; i++) {
        int y = n - 1 - i;
        ans = (ans - fact[y] * fact[i] % mod * choose(x, i) % mod) % mod;
    }
    cout << (ans + mod) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 2e5; i++)
        fact[i] = i * fact[i - 1] % mod;

    int T = 1;
    cin >> T;
    while (T--) solve();
}
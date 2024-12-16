#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 5e2 + 1;
const int mod = 998244353;
int fact[N], inv_num[N], inv_fact[N];

// O(N)
void build() {
    fact[0] = fact[1] = 1;
    inv_num[0] = inv_num[1] = 1;
    inv_fact[0] = inv_fact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = i * fact[i - 1] % mod;
        inv_num[i] = (mod - mod / i) * inv_num[mod % i] % mod;
        inv_fact[i] = inv_fact[i - 1] * inv_num[i] % mod;
    }
}

// O(1)
int choose(int n, int r) {
    assert(r <= n);
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

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

void add(int& a, int b) { a = (a + b % mod + mod) % mod; }

void solve() {
    int n, x; cin >> n >> x;

    v dp(x + 1, v<int>(n, -1));
    auto go = [&](int i, int j, auto&& self) -> int {
        if (i > x) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = 0;
        for (int k = j; k < n; k++)
            add(dp[i][j], self(i + k, k, self) * choose(n - j, k - j) % mod * binpow(k, k - j));

        if (j == n - 1 and (j != 1 or i != x)) dp[i][j]++;
        return dp[i][j];
    };

    int ans = binpow(x, n);
    for (int i = 1; i <= x; i++)
        add(ans, - go(i, 1, go) * n);
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
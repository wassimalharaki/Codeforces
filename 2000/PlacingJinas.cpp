#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 4e5 + 1;
const int mod = 1e9 + 7;
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
    if (r > n) return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

void solve() {
    int n; cin >> n;

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int x; cin >> x;
        ans = (ans + choose(x + i, i + 1)) % mod;
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
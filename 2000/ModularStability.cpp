#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 5e5 + 1;
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
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n, k; cin >> n >> k;

    int ans = 0;
    for (int i = 1; i <= n and n / i >= k; i++)
        add(ans, choose(n / i - 1, k - 1));
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
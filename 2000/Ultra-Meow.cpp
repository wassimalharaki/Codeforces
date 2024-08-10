#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 1e6 + 1;
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
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n; cin >> n;

    v<int> lt(2 * n + 2), gt(2 * n + 2);
    for (int i = 1; i <= 2 * n + 1; i++)
        lt[i] = i - 1;
    for (int i = 1; i <= 2 * n + 1; i++)
        gt[i] = max(0ll, n - i);

    int ans = 1;
    for (int i = 1; i <= 2 * n + 1; i++)
        for (int j = 1; j <= n; j++) {
            if (lt[i] < j) continue;
            int rem = lt[i] - j;
            if (rem > j) continue;
            if (min(lt[i], n) < rem) continue;
            int x = choose(min(lt[i], n), rem);
            int rest = j - rem;
            if (gt[i] < rest) continue;
            int y = choose(gt[i], rest);
            add(ans, i * x % mod * y % mod);
        }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    cin >> T;
    while (T--) solve();
}
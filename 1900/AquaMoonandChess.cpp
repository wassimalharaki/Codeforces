#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;
const int N = 1e5 + 1;
int fact[N], inv_num[N], inv_fact[N];

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

int choose(int n, int r) {
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int o = 0, z = 0, curr = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '1' and z == 0)
            o++;
        else if (s[i] == '1' and ++curr == 2)
            o += 2, curr = 0;
        else if (s[i] == '0')
            z++, curr = 0;
    cout << choose(z + o / 2, z) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    cin >> T;
    while (T--) solve();
}
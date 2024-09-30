#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 5e3 + 1;
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

void add(int& a, int b) {
    a = (a + b) % mod;
}

void sub(int& a, int b) {
    a = ((a - b) % mod + mod) % mod;
}

int get(int z, int o) {
    return fact[o + z] * binpow(fact[o], mod - 2) % mod
           * binpow(fact[z], mod - 2) % mod;
}

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    v<int> a;
    for (int i = 0; i < n - 1; i++)
        if (s[i + 1] == '1')
            a.push_back(i);
    a.push_back(n - 1);

    int pl = -1, pr = -1, ans = 1;
    for (int r : a) {
        int l = r, o = 0, z = 0;
        for (; l >= 0 and o <= k; l--)
            o += s[l] == '1', z += s[l] == '0';
        if (o < k) continue;
        if (o > k) l += 2, o--;
        if (l < 0) l++;
        add(ans, get(z, o));
        sub(ans, 1);
        o = 0, z = 0;
        for (int i = l; i <= pr; i++)
            o += s[i] == '1', z += s[i] == '0';
        tie(pl, pr) = {l, r};
        if (z == 0 and o == 0) continue;
        sub(ans, get(z, o));
        add(ans, 1);
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
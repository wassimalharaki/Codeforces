#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(N)
const int N = 70 + 1;
const int mod = 1e9 + 7;
vector<int> spf, primes;
void build() {
    spf.resize(N);
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] < N; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i])
                break;
        }
    }
}

// O(log(n))
vector<array<int, 2>> prime_factors(int n) {
    if (n == 1) return {};
    if (primes.empty()) build();

    vector<array<int, 2>> pfs{{spf[n], 1}};
    n /= spf[n];
    while (n != 1) {
        if (pfs.back()[0] == spf[n])
            pfs.back()[1]++;
        else
            pfs.push_back({spf[n], 1});
        n /= spf[n];
    }

    return pfs;
}

int fix(int x) {
    int z = 1;
    for (auto& [p, y] : prime_factors(x))
        if (y & 1)
            z *= p;
    return z;
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

const int M = 1e5 + 1;
int fact[M], inv_num[M], inv_fact[M];

// O(M)
void build2() {
    fact[0] = fact[1] = 1;
    inv_num[0] = inv_num[1] = 1;
    inv_fact[0] = inv_fact[1] = 1;
    for (int i = 2; i < M; i++) {
        fact[i] = i * fact[i - 1] % mod;
        inv_num[i] = (mod - mod / i) * inv_num[mod % i] % mod;
        inv_fact[i] = inv_fact[i - 1] * inv_num[i] % mod;
    }
}

// O(1)
int choose(int n, int r) {
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

void solve() {
    int n; cin >> n;

    v<int> a(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[fix(x)]++;
    }

    v<int> pin(N);
    {
        int k = 0;
        for (int& p : primes)
            pin[p] = k++;
    }
    
    int m = primes.size();
    v<int> dp(1 << m), ndp(1 << m);
    dp[0] = binpow(2, a[1]);
    for (int i = 2; i < N; i++) {
        if (a[i] == 0) continue;
        fill(ndp.begin(), ndp.end(), 0ll);
        
        int x = 0;
        for (auto& [p, y] : prime_factors(i))
            x += 1 << pin[p];

        int e = 0, o = 0;
        for (int j = 0; j <= a[i]; j += 2)
            e = (e + choose(a[i], j)) % mod;
        for (int j = 1; j <= a[i]; j += 2)
            o = (o + choose(a[i], j)) % mod;

        for (int j = 0; j < (1 << m); j++) {
            ndp[j] = (ndp[j] + dp[j] * e) % mod;
            ndp[j ^ x] = (ndp[j ^ x] + dp[j] * o) % mod;
        }
        
        dp.swap(ndp);
    }
    cout << dp[0] - 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build2();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
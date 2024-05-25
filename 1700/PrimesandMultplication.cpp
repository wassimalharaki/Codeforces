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

// O(Nlog(log(N)))
const int N = 4e4;
bitset<N> is_prime;
vector<int> primes;
void build() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    primes.push_back(2);
    for (int i = 4; i < N; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i < N; i += 2)
        if (is_prime[i])
            for (int j = i * i; j < N; j += i * 2)
                is_prime[j] = 0;

    for (int i = 3; i < N; i += 2)
        if (is_prime[i])
            primes.push_back(i);
}

// O(sqrt(n) / log(sqrt(n)))
vector<int> prime_set(int n) {
    if (primes.empty()) build();

    vector<int> pfs;
    for (const int& x : primes) {
        if (x * x > n) break;
        if (n % x) continue;
        pfs.push_back(x);
        while (n % x == 0) n /= x;
    }
    if (n != 1) pfs.push_back(n);
    
    return pfs;
}

const int mod = 1e9 + 7;

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

void solve() {
    int x, n; cin >> x >> n;

    v<int> primes = prime_set(x);
    int m = primes.size();
    v<v<int>> cnt(m, v<int>(64));
    for (int i = 0; i < m; i++) {
        int p = primes[i];
        for (int j = 1; p <= n; j++) {
            int x = n / p;
            cnt[i][j - 1] -= x;
            cnt[i][j] = x;
            int lim = LLONG_MAX / p;
            if (primes[i] > lim)
                p = LLONG_MAX;
            else
                p *= primes[i];
        }
    }

    int ans = 1;
    for (int i = 0; i < m; i++)
        for (int j = 1; j < 64; j++)
            ans = ans * binpow(primes[i], j * cnt[i][j]) % mod;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
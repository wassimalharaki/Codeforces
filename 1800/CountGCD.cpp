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
const int N = 4e4 + 1;
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
vector<int> prime_factors(int n) {
    if (primes.empty()) build();

    vector<int> pfs;
    for (const int& x : primes) {
        if (x * x > n) break;
        if (n % x) continue;
        pfs.push_back(x);
        while (n % x == 0)
            n /= x;
    }
    if (n != 1) pfs.push_back(n);
    
    return pfs;
}

const int mod = 998244353;

int get(int x, int n) {
    int ans = n;

    auto pfs = prime_factors(x);
    for (int mask = 1; mask < (1 << pfs.size()); mask++) {
        int y = 1;
        for (int i = 0; i < pfs.size(); i++)
            if ((1 << i) & mask)
                y *= pfs[i];
        ans += (__builtin_popcountll(mask) & 1 ? -1 : 1) * n / y;
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (gcd(a[i], a[i - 1]) != a[i]) {
            cout << 0 << nl;
            return;
        }
        ans = ans * get(a[i - 1] / a[i], m / a[i]) % mod;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
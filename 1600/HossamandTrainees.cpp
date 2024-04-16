#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

// O(Nlog(log(N)))
const int N = 4e4;
bitset<N + 1> is_prime;
vector<int> primes;
void build() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

    primes.push_back(2);
    for (int i = 4; i <= N; i += 2) 
        is_prime[i] = 0;

    for (int i = 3; i * i <= N; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= N; j += i * 2)
                is_prime[j] = 0;

    for (int i = 3; i <= N; i += 2)
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
        while (n % x == 0) n /= x;
    }
    if (n != 1) pfs.push_back(n);
    
    return pfs;
}

void solve() {
    int n; cin >> n;

    set<int> ok;
    bool can = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (can) continue;
        v<int> pfs = prime_factors(a);
        for (int& p : pfs)
            if (ok.count(p)) {
                can = 1;
                break;
            }
            else
                ok.insert(p);
    }
    cout << (can ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
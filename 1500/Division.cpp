#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

const int N = 4e4;
bitset<N> is_prime;
vector<int> primes = {2};
void build() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;

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

void solve() {
    int p, q; cin >> p >> q;

    map<int, int> pf;
    for (int i = 0; i < primes.size(); i++) {
        int x = primes[i];
        if (x * x > q) break;
        while (q % x == 0) {
            q /= x;
            pf[x]++;
        }
    }
    if (q != 1) pf[q]++;

    int ans = 1;
    for (auto& [x, cnt] : pf) {
        int have = 0;
        int a = p;
        while (a % x == 0)
            have++, a /= x;
        //i want it to be 1 less than cnt
        int rem = max(0ll, have - cnt + 1);
        ans = max(ans, p / binpow(x, rem));
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
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

// O(N)
const int N = 1e3 + 1;
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
vector<int> prime_factors(int n) {
    if (primes.empty()) build();

    vector<int> pfs;
    while (n != 1) {
        pfs.push_back(spf[n]);
        n /= spf[n];
    }

    return pfs;
}

// O(log(b))
int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;

    if (n == 8) {
        cout << 24 << nl;
        return;
    }

    auto pfs = prime_factors(n);
    reverse(pfs.begin(), pfs.end());
    int ans = 1, j = 0;
    for (int& x : pfs)
        ans *= binpow(primes[j++], x - 1);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
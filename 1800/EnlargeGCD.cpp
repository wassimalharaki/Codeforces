#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

// O(N)
const int N = 15e6 + 1;
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
    if (n == 1) return {};
    if (primes.empty()) build();

    vector<int> pfs{spf[n]};
    n /= spf[n];
    while (n != 1) {
        if (pfs.back() != spf[n])
            pfs.push_back(spf[n]);
        n /= spf[n];
    }

    return pfs;
}

void solve() {
    int n; cin >> n;

    int g = 0;
    v<int> a(n);
    for (int& x : a) {
        cin >> x;
        g = __gcd(g, x);
    }
    for (int& x : a) x /= g;

    if (count(a.begin(), a.end(), a[0]) == n) {
        cout << -1 << nl;
        return;
    }
    
    v<int> cnt(N + 1);
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        auto pfs = prime_factors(a[i]);
        for (int& p : pfs)
            ans = min(ans, n - ++cnt[p]);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
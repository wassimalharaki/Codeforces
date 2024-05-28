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
const int N = 1e7 + 1;
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
    auto pfs = prime_factors(x);
    x = 1;
    for (auto& [p, cnt] : pfs)
        if (cnt & 1)
            x *= p;
    return x;
}

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) {
        cin >> x;
        x = fix(x);
    }

    set<int> have;
    int ans = 1;
    for (int& x : a)
        if (have.count(x)) {
            have.clear();
            have.insert(x);
            ans++;
        }
        else
            have.insert(x);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
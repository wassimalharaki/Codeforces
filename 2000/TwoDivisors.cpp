#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

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
vector<int> prime_factors(int n) {
    if (primes.empty()) build();
    if (n == 1) return {};

    vector<int> pfs;
    while (n != 1) {
        if (pfs.empty() or pfs.back() != spf[n])
            pfs.push_back(spf[n]);
        n /= spf[n];
    }

    return pfs;
}

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n, {-1, -1});
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        auto pfs = prime_factors(x);
        if (pfs.size() == 1) continue;
        int p = pfs[0], q = 1;
        for (int& x : pfs) q *= x;
        a[i] = {p, q / p};
    }

    for (auto& x : a)
        cout << x[0] << " ";
    cout << nl;
    for (auto& x : a)
        cout << x[1] << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
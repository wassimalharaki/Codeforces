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
const int N = 5e6;
vector<int> spf, primes;
void build() {
    spf = vector<int>(N + 1);
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] <= N; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i])
                break;
        }
    }
}

// O(log(n))
int prime_factors(int n) {
    if (primes.empty()) build();

    int ans = 0;
    while (n != 1) {
        n /= spf[n];
        ans++;
    }
    return ans;
}

int prefix[N + 1];

void solve() {
    int a, b; cin >> a >> b;
    cout << prefix[a] - prefix[b] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prefix[0] = 0;
    for (int i = 1; i <= N; i++)
        prefix[i] = prefix[i - 1] + prime_factors(i);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
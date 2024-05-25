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
const int N = 1e6 + 1;
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
int divisors(int n) {
    if (primes.empty()) build();
    int cnt = 1, curr = 0, prev = -1;
    while (n != 1) {
        if (spf[n] == prev)
            curr++;
        else {
            prev = spf[n];
            cnt *= curr + 1;
            curr = 1;
        }
        n /= spf[n];
    }
    cnt *= curr + 1;

    return cnt;
}

const int mod = 998244353;

void solve() {
    int n; cin >> n;

    v<int> dp(n + 1);
    dp[0] = 1;
    int x = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (divisors(i) - 1 + x) % mod;
        x = (x + dp[i]) % mod;
    }
    cout << dp[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
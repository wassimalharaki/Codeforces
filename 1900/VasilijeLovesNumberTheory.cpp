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

int binpow(int a, int b, const int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;

    map<int, int> back, pfs;
    int y = n;
    while (n != 1) {
        ++back[spf[n]];
        n /= spf[n];
    }
    n = y; pfs = back;

    while (q--) {
        int k; cin >> k;
        if (k == 2)
            pfs = back;
        else {
            int x; cin >> x;
            
            while (x != 1) {
                ++pfs[spf[x]];
                x /= spf[x];
            }

            int d = 1;
            for (auto& [key, val] : pfs)
                d *= val + 1;

            int res = 1;
            for (auto& [key, val] : pfs)
                res = res * binpow(key, val, d) % d;
            res %= d;

            cout << (res == 0 ? "YES" : "NO") << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    build();
    int T = 1;
    cin >> T;
    while (T--) solve();
}
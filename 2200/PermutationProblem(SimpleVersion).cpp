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
const int N = 5e5 + 1;
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

// O(d(n^p))
vector<int> gen_divisors(const vector<array<int, 2>>& pfs) {
    vector<int> divs{1};

    auto f = [&](int x, int i, auto&& f) -> void {
        if (i >= pfs.size()) return;
        f(x, i + 1, f);
        for (int j = 0; j < pfs[i][1]; j++) {
            x *= pfs[i][0];
            divs.push_back(x);
            f(x, i + 1, f);
        }
    };
    f(1, 0, f);

    // sort(divs.begin(), divs.end());
    return divs;
}

// O(log(n) + d(n^p))
vector<int> divisors(int n, int p = 1) {
    if (n == 1) return {1};
    if (primes.empty()) build();

    vector<array<int, 2>> pfs{{spf[n], p}};
    n /= spf[n];
    while (n != 1) {
        if (pfs.back()[0] == spf[n])
            pfs.back()[1] += p;
        else
            pfs.push_back({spf[n], p});
        n /= spf[n];
    }

    return gen_divisors(pfs);
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    long long ans = 0;
    v<map<int, int>> b(n + 1);
    for (int i = 0; i < n; i++) {
        int num = a[i], deno = i + 1;
        int g = gcd(num, deno);
        num /= g, deno /= g;
        for (int& d : divisors(num))
            for (auto& [x, y] : b[d])
                if (x % deno == 0)
                    ans += y;
        b[deno][num]++;
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
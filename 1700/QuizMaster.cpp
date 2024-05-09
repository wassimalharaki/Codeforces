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
const int N = 1e5 + 1;
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
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    map<int, int> cnt;
    int l = 0, r = -1, ans = INT_MAX;
    while (1) 
        if (cnt.size() < m) {
            if (++r == n) break;
            auto divs = divisors(a[r]);
            for (int& d : divs)
                if (d <= m)
                    cnt[d]++;
        }
        else {
            ans = min(ans, a[r] - a[l]);
            auto divs = divisors(a[l++]);
            for (int& d : divs)
                if (d <= m)
                    if (--cnt[d] == 0)
                        cnt.erase(d);
        }
    cout << (ans == INT_MAX ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
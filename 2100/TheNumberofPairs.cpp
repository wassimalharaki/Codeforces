#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(N)
const int N = 2e7 + 1;
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
        if (i >= (int) pfs.size()) return;
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
    if (primes.empty()) build();
    if (n == 1) return {1};

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

// O(log(n))
int prime_factors(int n) {
    if (n == 1) return 0;

    int sz = 1, prev = spf[n];
    n /= spf[n];
    while (n != 1) {
        if (prev != spf[n])
            prev = spf[n], sz++;
        n /= spf[n];
    }

    return sz;
}

void solve() {
    int c, d, x; cin >> c >> d >> x;

    int ans = 0;
    for (int& g : divisors(x))
        if ((x / g + d) % c == 0)
            ans += 1 << prime_factors((x / g + d) / c);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
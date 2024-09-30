#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(N)
const int N = 2e5 + 1;
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

const int mod = 1e9 + 7;

// O(log(b))
long long binpow(long long a, int b, const int m = mod) {
    a %= m;
    long long res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;

    build();
    int m = 0;
    v<int> id(N);
    for (int& p : primes) id[p] = m++;
    v<multiset<int>> cnt(m);

    v<map<int, int>> a(n);
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        auto pf = prime_factors(x);
        for (auto& [p, y] : pf) {
            a[i][p] = y;
            cnt[id[p]].insert(y);
        }
    }

    long long g = 1;
    for (int i = 0; i < m; i++)
        if (cnt[i].size() == n)
            g *= binpow(primes[i], *cnt[i].begin());

    while (q--) {
        int i, x; cin >> i >> x; i--;

        auto pf = prime_factors(x);
        for (auto& [p, y] : pf) {
            int prev = 0;
            if (cnt[id[p]].size() == n)
                prev = *cnt[id[p]].begin();

            if (a[i].count(p))
                cnt[id[p]].erase(cnt[id[p]].find(a[i][p]));
            a[i][p] += y;
            cnt[id[p]].insert(a[i][p]);

            int next = 0;
            if (cnt[id[p]].size() == n)
                next = *cnt[id[p]].begin();

            g = g * binpow(p, next - prev) % mod;
        }
        cout << g << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
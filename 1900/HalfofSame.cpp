#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(N)
const int N = 2e6 + 1;
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
    if (n == 0) return {};
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

bitset<N> have;

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    have.reset();

    for (int i = 0; i < n; i++)    
        if (count(a.begin(), a.end(), a[i]) >= n / 2) {
            cout << -1 << nl;
            return;
        }

    for (int i = 0; i < n; i++)
        for (int j = i - 1; j >= 0; j--)
            for (int& d : divisors(a[i] - a[j]))
                have[d] = 1;

    for (int i = N - 1; i; i--) {
        if (not have[i]) continue;
        for (int j = n / 2; j >= 0; j--) {
            int cnt = 1;
            for (int k = j + 1; k < n; k++)
                cnt += (a[k] - a[j]) % i == 0;
            if (cnt >= n / 2) {
                cout << i << nl;
                return;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
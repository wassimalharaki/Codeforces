#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(N)
const int N = 5e6 + 1;
vector<int> spf(N), primes;
void build() {
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

    auto f = [&](int x, int i, auto&& self) -> void {
        if (i >= (int) pfs.size()) return;
        self(x, i + 1, self);
        for (int j = 0; j < pfs[i][1]; j++) {
            x *= pfs[i][0];
            divs.push_back(x);
            self(x, i + 1, self);
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

void solve() {
    int n; cin >> n;

    v<int> a(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a[x]++;
    }

    for (int i = 1; i < N; i++)
        for (int j = 2 * i; j < N; j += i)
            a[i] += a[j];
    
    v<int> dp(N); dp[1] = n;
    for (int i = 1; i < N; i++)
        if (a[i])
            for (int& d : divisors(i))
                dp[i] = max(dp[i], dp[d] + (i - d) * a[i]);
    cout << *max_element(dp.begin(), dp.end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
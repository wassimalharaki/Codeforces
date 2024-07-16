#include <bits/stdc++.h>
using namespace std;
#define int long long
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

    sort(divs.begin(), divs.end());
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
    int n, x; cin >> n >> x;

    v<int> a(n);
    for (int& y : a) cin >> y;

    v<int> cnt(x + 1), have(x + 1);
    auto div = divisors(x);
    for (int& d : div)
        cnt[d] = 1;

    int ans = 0;
    for (int i = 0; i < n;) {
        have[1] = 1;
        ans++;
        while (i < n and not have[x]) {
            for (int j = div.size() - 1; j >= 0; j--) {
                int d = div[j];
                if (have[d] and a[i] * d <= x and cnt[a[i] * d])
                    have[a[i] * d] = 1;
            }
            i++;
        }
        if (have[x]) i--;
        for (int& d : div)
            have[d] = 0;
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
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

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

int fix(int x) {
    int y = 1;
    for (auto& [p, cnt] : prime_factors(x))
        if (cnt & 1)
            y *= p;
    return y;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a)
        cin >> x, x = fix(x);
    sort(a.begin(), a.end());

    v<array<int, 2>> b{{a[0], 1}};
    for (int i = 1; i < n; i++)
        if (a[i] == a[i - 1])
            b.back()[1]++;
        else
            b.push_back({a[i], 1});

    int ans1 = 0, ans2 = 0;
    for (auto& [x, y] : b) {
        ans1 = max(ans1, y);
        if ((y & 1 ^ 1) or x == 1) ans2 += y;
    }

    int q; cin >> q;
    while (q--) {
        int64_t x; cin >> x;
        cout << (x ? max(ans1, ans2) : ans1) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
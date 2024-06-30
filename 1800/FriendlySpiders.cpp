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
const int N = 3e5 + 1;
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
v<int> prime_factors(int n) {
    if (primes.empty()) build();

    vector<int> pfs;
    while (n != 1) {
        if (pfs.empty() or pfs.back() != spf[n])
            pfs.push_back(spf[n]);
        n /= spf[n];
    }

    return pfs;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    v<v<int>> have(N);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        auto pfs = prime_factors(a[i]);
        a[i] = 1;
        for (int& p : pfs) {
            a[i] *= p;
            have[p].push_back(i);
        }
    }
    int s, t; cin >> s >> t; s--, t--;
    if (s == t) {
        cout << 1 << nl << s + 1 << nl;
        return;
    }

    v<int> p(n, -1);
    queue<int> q;
    p[s] = -2;
    q.push(s);

    while (q.size()) {
        int u = q.front();
        if (u == t) break;
        q.pop();

        for (int& pf : prime_factors(a[u])) {
            for (int& i : have[pf])
                if (p[i] == -1) {
                    p[i] = u;
                    q.push(i);
                }
            have[pf].clear();
        }
    }

    if (p[t] == -1) {
        cout << -1 << nl;
        return;
    }

    v<int> path;
    for (int u = t; u != -2; u = p[u])
        path.push_back(u);
    reverse(path.begin(), path.end());

    cout << path.size() << nl;
    for (int& x : path)
        cout << x + 1 << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
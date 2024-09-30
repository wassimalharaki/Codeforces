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
    if (primes.empty()) build();
    if (n == 1) return {};

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

void solve() {
    int n; cin >> n;

    v<int> a(n);
    v<v<int>> b(N), adj(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (auto& [p, y] : prime_factors(a[i]))
            b[p].push_back(i);
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int mxD, j;
    v<int> dis(n);
    auto dfs = [&](int u, int p, int d, int x, auto&& dfs) -> void {
        dis[u] = d;
        if (d > mxD)
            mxD = d, j = u;
        for (int& i : adj[u])
            if (i != p and a[i] % x == 0)
                dfs(i, u, d + 1, x, dfs);
    };

    int ans = 0;
    for (int& p : primes) {
        for (int& i : b[p]) {
            if (dis[i]) continue;
            mxD = 0;
            dfs(i, -1, 1, p, dfs);
            mxD = 0;
            dfs(j, -1, 1, p, dfs);
            ans = max(ans, mxD);
        }
        for (int& i : b[p])
            dis[i] = 0;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
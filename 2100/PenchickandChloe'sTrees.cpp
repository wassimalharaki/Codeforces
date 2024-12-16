#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int p; cin >> p;
        adj[p - 1].push_back(i + 1);
    }

    auto dfs = [&](int u, auto&& self) -> int {
        v<int> a;
        for (int& i : adj[u])
            a.push_back(self(i, self));
        sort(a.begin(), a.end());
        if (a.empty()) return 0;
        if (a.size() == 1) return 1 + a[0];

        int x = 0, y = 0;
        for (int& z : a) {
            if (x) x = ((x - 1) >> min(31ll, (z - y))) + 1;
            y = z, x++;
        }
        return y + (x > 1 ? __lg(x - 1) + 1 : 1);
    };
    cout << dfs(0, dfs) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
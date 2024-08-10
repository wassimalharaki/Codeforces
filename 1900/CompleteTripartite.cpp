#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

mt19937_64 gen(random_device{}());
uniform_int_distribution<int> dist(0, LLONG_MAX);

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> hash(n);
    for (int& x : hash)
        x = dist(gen);

    map<int, v<int>> comps;
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int& y : adj[i])
            x ^= hash[y];
        comps[x].push_back(i);
    }

    if (comps.size() != 3)
        cout << -1 << nl;
    else {
        int i = 1, sz = 0;
        v<int> ans(n);
        for (auto& [_, a] : comps) {
            for (int& x : a)
                ans[x] = i;
            sz += a.size();
            i++;
        }
        for (auto& [_, a] : comps) {
            sz -= a.size();
            for (int& x : a)
                if (adj[x].size() != sz) {
                    cout << -1 << nl;
                    return;
                }
            sz += a.size();
        }
        for (int& x : ans)
            cout << x << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
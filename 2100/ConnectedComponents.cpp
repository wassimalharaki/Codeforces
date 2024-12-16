#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (auto& x : adj)
        sort(x.begin(), x.end());
    
    auto go = [&](int a, int b) {
        return not binary_search(adj[a].begin(), adj[a].end(), b);
    };
    
    set<int> alive;
    for (int i = 0; i < n; i++)
        alive.insert(i);
    
    int sz = 0;
    auto dfs = [&](int u, auto&& self) -> void {
        sz++;

        v<int> exp;
        for (int i : alive)
            if (go(u, i))
                exp.push_back(i);
        
        for (int& i : exp)
            alive.erase(i);
        for (int& i : exp)
            self(i, self);
    };

    v<int> ans;
    for (int i = 0; i < n; i++)
        if (alive.count(i)) {
            sz = 0;
            alive.erase(i);
            dfs(i, dfs);
            ans.push_back(sz);
        }
    sort(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for (int& x : ans)
        cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
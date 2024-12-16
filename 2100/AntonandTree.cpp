#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

struct small {
    v<array<int, 2>> a;
    small() {}
    void add(int x, int i) {
        a.push_back({x, i});
        sort(a.rbegin(), a.rend());
        while (a.size() > 2)
            a.pop_back();
    }
    array<int, 2> first() {
        return a.front();
    }
    array<int, 2> second() {
        return a.back();
    }
};

void solve() {
    int n; cin >> n;


    v<int> a(n);
    for (int& x : a) cin >> x;
    if (n == 1)
        return void(cout << 0 << nl);
    if (n == 2)
        return void(cout << (a[0] != a[1]) << nl);

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    v<small> dp(n);
    auto dfs = [&](int u, int p, auto&& self) -> void {
        dp[u].add(0, u);
        for (int& i : adj[u]) if (i != p) {
            self(i, u, self);
            dp[u].add(dp[i].first()[0] + (a[i] != a[u]), i);
        }
    };
    dfs(0, -1, dfs);

    auto reroot = [&](int u, int p, auto&& self) -> void {
        if (p != -1) {
            if (dp[p].first()[1] != u)
                dp[u].add(dp[p].first()[0] + (a[u] != a[p]), p);
            if (dp[p].second()[1] != u)
                dp[u].add(dp[p].second()[0] + (a[u] != a[p]), p);
        }
        for (int& i : adj[u])
            if (i != p) self(i, u, self);
    };
    reroot(0, -1, reroot);

    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[i].first()[0]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
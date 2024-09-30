#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, s; cin >> n >> s;

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    auto get = [&](int c, int cnt) -> int {
        return (c + 1) / 2 * cnt;  
    };

    int x = 0;
    v<int> cnt(n);
    priority_queue<array<int, 3>> cont;
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        if (p != -1 and adj[u].size() == 1)
            cnt[u]++;
        for (auto& [i, c] : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                cont.push({
                    get(c, cnt[i]),
                    c, cnt[i]
                });
                x += c * cnt[i];
                cnt[u] += cnt[i];
            }
    };
    dfs(0, -1, dfs);

    int ans = 0;
    while (x > s) {
        auto [d, y, c] = cont.top();
        cont.pop();
        x -= d; y /= 2; ans++;
        cont.push({
            get(y, c),
            y, c
        });
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
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v a(n, v<int>(m));
    for (auto& x : a) {
        string s; cin >> s;
        for (int i = 0; i < m; i++)
            x[i] = s[i] == '.';
    }

    v vis(n, v<int>(m));
    auto dfs = [&](int i, int j, auto&& dfs) -> void {
        if (i >= n or j >= m) return;
        if (!a[i][j] or vis[i][j]) return;
        vis[i][j] = 1;
        dfs(i + 1, j, dfs); dfs(i, j + 1, dfs);
    };
    dfs(0, 0, dfs);
    
    if (not vis[n - 1][m - 1]) {
        cout << 0 << nl;
        return;
    }
    a.swap(vis);
    fill(vis.begin(), vis.end(), v<int>(m));

    v<int> dist(n + m);
    queue<array<int, 3>> q;
    q.push({0, n - 1, m - 1});
    vis[n - 1][m - 1] = 1;

    while (q.size()) {
        auto [d, i, j] = q.front();
        q.pop();
        dist[d]++;

        if (i - 1 >= 0 and a[i - 1][j] and not vis[i - 1][j]) {
            q.push({d + 1, i - 1, j});
            vis[i - 1][j] = 1;
        }

        if (j - 1 >= 0 and a[i][j - 1] and not vis[i][j - 1]) {
            q.push({d + 1, i, j - 1});
            vis[i][j - 1] = 1;
        }
    }
    cout << (count(dist.begin(), dist.end(), 1) >= 3 ? 1 : 2) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;
    const int N = 26;

    v<string> s(n);
    for (auto& t : s) cin >> t;

    v<v<int>> adj(N, v<int>(N));
    for (int i = 0; i < n - 1; i++) {
        int x = s[i].size(), y = s[i + 1].size();
        int j = 0;
        while (j < x and j < y)
            if (s[i][j] == s[i + 1][j]) j++;
            else break;
        if (j == x or j == y) {
            if (x > y) {
                cout << "Impossible";
                return;
            }
        }
        else
            adj[s[i][j] - 'a'][s[i + 1][j] - 'a'] = 1;
    }

    v<char> color(N);
    auto dfs1 = [&](int u, auto&& dfs1) -> bool {
        color[u] = 1;
        for (int a = 0; a < N; a++) {
            if (adj[u][a] == 0) continue;
            if ((color[a] == 0 and dfs1(a, dfs1)) or color[a] == 1)
                return 1;
        }
        color[u] = 2;
        return 0;
    };

    for (int i = 0; i < N; i++)
        if (color[i] == 0 and dfs1(i, dfs1)) {
            cout << "Impossible";
            return;
        }
    
    v<bool> vis(N);
    v<int> ans;
    auto dfs2 = [&](int u, auto&& dfs2) -> void {
        vis[u] = 1;
        for (int a = 0; a < N; a++)
            if (adj[u][a] and not vis[a])
                dfs2(a, dfs2);
        ans.push_back(u);
    };

    for (int i = 0; i < N; i++)
        if (not vis[i])
            dfs2(i, dfs2);

    reverse(all(ans));
    for (int& a : ans)
        cout << char(a + 'a');
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
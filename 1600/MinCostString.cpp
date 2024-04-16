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
    int n, k; cin >> n >> k;
    v<v<bool>> vis(k, v<bool>(k));

    string s;
    auto dfs = [&](int u, auto&& dfs) -> void {
        s += char('a' + u);
        for (int i = k - 1; i >= 0; i--)
            if (not vis[u][i]) {
                vis[u][i] = 1;
                dfs(i, dfs);
            }
    };
    dfs(0, dfs);

    string t = s.substr(1, s.size() - 1);
    while (s.size() < n)
        s += t;
    while (s.size() > n)
        s.pop_back();
    cout << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
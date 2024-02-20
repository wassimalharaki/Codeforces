#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n, m; cin >> n >> m;

    vi cat(n);
    for (int& a : cat) cin >> a;

    vvi adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = 0;
    auto dfs = [&](int u, int p, int curr, auto&& dfs) -> void {
        if (cat[u - 1]) curr++;
        else curr = 0;
        if (curr > m) return;
        if (adj[u].size() == 1 and adj[u][0] == p)
            ans++;
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, curr, dfs);
    };
    dfs(1, -1, 0, dfs);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
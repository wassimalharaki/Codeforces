#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
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

    vi nums(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    
    vvi adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int min = INF;
    function<void(int)> dfs = [&](int u) {
        min = std::min(min, nums[u]);
        for (auto i : adj[u])
            if (not vis[i])
                vis[i] = 1, dfs(i);
    };

    int answ = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1; dfs(i);
        answ += min; min = INF;
    }
    cout << answ;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
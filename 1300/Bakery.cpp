#include <bits/stdc++.h>

using namespace std;

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
    int n, m, k; cin >> n >> m >> k;

    v<vpii> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }

    v<bool> ok(n);
    vi bakery(k);
    for (int i = 0; i < k; i++) {
        cin >> bakery[i];
        bakery[i]--;
        ok[bakery[i]] = 1;
    }

    int ans = INF;
    for (auto& b : bakery)
        for (auto& [u, c] : adj[b])
            if (not ok[u])
                ans = min(ans, c);
    cout << (ans == INF ? -1 : ans);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
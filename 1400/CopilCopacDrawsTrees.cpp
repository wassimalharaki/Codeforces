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
    int n; cin >> n;

    v<vpii> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(mp(b, i));
        adj[b].pb(mp(a, i));
    }
    vi app(n + 1, INT_MAX), ok(app);
    ok[1] = 1, app[1] = -1;

    queue<int> q; q.push(1);
    v<bool> vis(n + 1); vis[1] = 1;
    while (not q.empty()) {
        int u = q.front(); q.pop();
        for (pii& p : adj[u]) {
            if (ok[u] + (p.S < app[u]) < ok[p.F]) {
                ok[p.F] = ok[u] + (p.S < app[u]);
                app[p.F] = p.S;
            }
            if (not vis[p.F]) {
                vis[p.F] = 1;
                q.push(p.F);
            }
        }
    }
    cout << *max_element(1 + all(ok)) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
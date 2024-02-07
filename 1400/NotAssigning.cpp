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

    map<pii, pii> edges;
    vvi adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        edges[mp(a, b)] = edges[mp(b, a)] = mp(i, -1);
    }

    bool ok = 1;
    for (vi& a : adj)
        if (a.size() > 2)
            ok = 0;
    
    if (not ok) {
        cout << -1 << nl;
        return;
    }

    int a = -1;
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 1)
            a = i;
    
    int alt = 1;
    for (int i = 0; i < n; i++) {
        int b = adj[a][0];
        if (edges[mp(a, b)].S != -1) {
            if (adj[a].size() == 1)
                break;
            b = adj[a][1];
        }
        edges[mp(a, b)].S = edges[mp(b, a)].S = (alt ? 2 : 5);
        a = b;
        alt = !alt;
    }

    vi ans(n - 1);
    for (auto& [key, val] : edges)
        ans[val.F] = val.S;
    for (int& i : ans)
        cout << i << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
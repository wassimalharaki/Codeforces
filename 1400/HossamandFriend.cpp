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

    v<set<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int l = 1, r = 1, ans = 0;
    vpii prev;
    auto upd = [&]() {
        ans += (r - l) * (r - l + 1) / 2;
        if (not prev.empty())
            ans -= (prev.back().S - l) * (prev.back().S - l + 1) / 2;
        prev.pb(mp(l, r));
    };
    while (r <= n) {
        if (++r > n) {
            upd();
            break;
        }
        auto it = adj[r].lower_bound(l);
        if (it == adj[r].end()) continue;
        if (*it > r) continue;
        upd();
        l = *(--adj[r].lower_bound(r)) + 1;
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
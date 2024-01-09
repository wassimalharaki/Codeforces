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
    int n; cin >> n;

    vvi adj(n + 1, vi());
    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        adj[a].pb(i + 1);
    }

    bool ok = 1;
    function<void(int)> dfs = [&](int u) {
        if (adj[u].empty())
            return;
        int c = 0;
        for (auto i : adj[u])
            c += adj[i].empty();
        if (c < 3) {
            ok = 0;
            return;
        }
        for (auto i : adj[u])
            dfs(i);
    };
    dfs(1);
    cout << (ok ? "Yes" : "No") nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
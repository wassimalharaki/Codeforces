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
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi leaves(n + 1);
    function<int(int c, int p)> dfs = [&](int c, int p) -> int {
        if (adj[c].size() == 1 and p != -1)
            return leaves[c] = 1;
        int sum = 0;
        for (int i : adj[c])
            if (i != p)
                sum += dfs(i, c);
        leaves[c] = sum;
        return sum;
    };
    dfs(1, -1);

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        cout << leaves[a] * leaves[b] nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
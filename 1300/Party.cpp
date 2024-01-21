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
    int n, m; cin >> n >> m;

    vi nums(n);
    for (int& a : nums) cin >> a;

    vvi adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    if (!(m & 1)) {
        cout << 0 << nl;
        return;
    }

    int ans = INF;
    for (int i = 0; i < n; i++)
        if (adj[i].size() & 1)
            ans = min(ans, nums[i]);
        else
            for (auto& j : adj[i])
                if (!(adj[j].size() & 1))
                    ans = min(ans, nums[i] + nums[j]);
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
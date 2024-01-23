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
    int n; cin >> n;

    vvi adj(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a--;
        if (i == a) {
            root = i;
            continue;
        }
        adj[a].pb(i);
    }

    vvi ans;
    vi path;
    auto dfs = [&](int u, auto&& dfs) -> void {
        path.pb(u);
        for (auto& i : adj[u])
            dfs(i, dfs);
        if (not path.empty())
            ans.pb(path);
        path.clear();
    };
    dfs(root, dfs);

    cout << ans.size() << nl;
    for (vi& nums : ans) {
        cout << nums.size() << nl;
        for (int& i : nums) cout << i + 1 << " ";
        cout << nl;
    }
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
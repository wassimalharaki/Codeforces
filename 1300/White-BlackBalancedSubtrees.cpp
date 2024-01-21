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

    vi nums(n - 1);
    for (int& a : nums) cin >> a;
    string s; cin >> s;

    vvi adj(n);
    for (int i = 0; i < n - 1; i++)
        adj[nums[i] - 1].pb(i + 1);
    
    vi val(n, -INF);
    auto dfs = [&](int u, auto&& dfs) -> void {
        val[u] = (s[u] == 'W' ? 1 : -1);
        for (auto i : adj[u]) {
            if (val[i] == -INF)
                dfs(i, dfs);
            val[u] += val[i];
        }
    };
    dfs(0, dfs);
    cout << count(all(val), 0ll) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
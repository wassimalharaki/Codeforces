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

/*
if im going to remove a vertex, then
all of its children will also be removed
and the order does not matter
basically im removing subtrees, and i can sort
the order of removal before printing
if value of subtree = its size
it has to be removed
*/

void solve() {
    int n; cin >> n;

    int root;
    vvi adj(n + 1);
    vi nums(n + 1);
    for (int i = 1; i <= n; i++) {
        int p; cin >> p >> nums[i];
        if (p == -1) root = i;
        else adj[p].pb(i);
    }

    vi del;
    auto dfs = [&](int u, auto&& dfs) -> void {
        int val = nums[u];
        for (int& i : adj[u]) {
            dfs(i, dfs);
            val += nums[i];
        }
        if (val == adj[u].size() + 1 and u != root)
            del.pb(u);
    };
    dfs(root, dfs);

    sort(all(del));
    for (int& a : del) cout << a << " ";
    if (del.empty()) cout << -1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}
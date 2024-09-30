#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    int rt = 0, sum = 0;
    v<int> a(n), p(n);
    v<v<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> a[i];
        sum += a[i], p[i]--;
        if (p[i] == -1) rt = i;
        else adj[p[i]].push_back(i);
    }

    if (sum % 3) {
        cout << -1 << nl;
        return;
    }
    sum /= 3;

    int j = -1;
    v<int> dp(n), dead(n), depth(n);
    auto dfs = [&](int u, bool k, int d, auto&& dfs) -> int {
        k |= u == j;
        depth[u] = d;
        dead[u] = k;
        dp[u] = k ? 0 : a[u];
        for (int& i : adj[u])
            dp[u] += dfs(i, k, d + 1, dfs);
        return dp[u];
    };
    dfs(rt, 0, 0, dfs);

    for (int i = 0; i < n; i++)
        if (dp[i] == sum and i != rt and (j == -1 or depth[j] < depth[i]))
            j = i;
    if (j == -1) {
        cout << -1 << nl;
        return;
    }
    dfs(rt, 0, 0, dfs);

    for (int i = 0; i < n; i++)
        if (dp[i] == sum and i != rt and not dead[i]) {
            cout << j + 1 << " " << i + 1 << nl;
            return;
        }
    cout << -1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
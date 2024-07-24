#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> adj(n), adj_rev(n);;
    for (int i = 0; i < n; i++) {
        if (i - a[i] >= 0) {
            adj[i].push_back(i - a[i]);
            adj_rev[i - a[i]].push_back(i);
        }
        if (i + a[i] < n) {
            adj[i].push_back(i + a[i]);
            adj_rev[i + a[i]].push_back(i);   
        }
    }

    v<array<int, 2>> dp(n, {INT_MAX, INT_MAX});
    for (int i = 0; i < n; i++)
        dp[i][a[i] & 1] = 0;
    
    queue<int> q;
    v<int> vis(n);
    for (int i = 0; i < n; i++) {
        for (int& j : adj[i])
            if ((a[i] ^ a[j]) & 1)
                dp[i][a[i] & 1 ^ 1] = 1;
        if (dp[i][a[i] & 1 ^ 1] == 1) {
            q.push(i);
            vis[i] = 1;
        }
    }

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int& i : adj_rev[u])
            if (not vis[i]) {
                vis[i] = 1;
                dp[i][a[i] & 1 ^ 1] = 1 + dp[u][a[u] & 1 ^ 1];
                q.push(i);
            }
    }

    v<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = dp[i][a[i] & 1 ^ 1];
        if (ans[i] == INT_MAX) ans[i] = -1;
    }
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
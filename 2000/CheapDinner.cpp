#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    array<int, 4> n;
    for (int& x : n) cin >> x;
    
    array<v<int>, 4> a, dp;
    for (int i = 0; i < 4; i++) {
        a[i].resize(n[i]);
        dp[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            dp[i][j] = a[i][j];
        }
    }

    array<v<v<int>>, 3> adj;
    for (int i = 0; i < 3; i++) {
        adj[i].resize(n[i]);
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int x, y; cin >> x >> y;
            adj[i][x - 1].push_back(y - 1);
        }
    }

    multiset<int> ok;
    for (int& x : dp[3])
        ok.insert(x);
    
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < n[i]; j++) {
            v<int> b;
            for (int& k : adj[i][j])
                if (dp[i + 1][k] != -1) {
                    b.push_back(dp[i + 1][k]);
                    ok.erase(ok.find(dp[i + 1][k]));
                }

            if (ok.size())
                dp[i][j] += *ok.begin();
            else
                dp[i][j] = -1;
            
            for (int& x : b)
                ok.insert(x);
        }

        ok.clear();
        for (int& x : dp[i])
            if (x != -1)
                ok.insert(x);
    }

    int ans = INT_MAX;
    for (int& x : dp[0])
        if (x != -1)
            ans = min(ans, x);
    cout << (ans == INT_MAX ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
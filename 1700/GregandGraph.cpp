#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n, v<int>(n));
    for (auto& a : adj)
        for (auto& b : a)
            cin >> b;

    v<int> nums(n);
    v<bool> alive(n);
    for (int& a : nums) cin >> a;
    
    v<v<int>> dist(n, v<int>(n, 1e10));
    v<int> ans;
    for (int k = n - 1; k >= 0; k--) {
        int x = --nums[k];

        alive[x] = 1;
        for (int i = 0; i < n; i++)
            if (alive[i]) {
                dist[x][i] = adj[x][i];
                dist[i][x] = adj[i][x];
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[x][j] > dist[x][i] + dist[i][j])
                    dist[x][j] = dist[x][i] + dist[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[j][x] > dist[j][i] + dist[i][x])
                    dist[j][x] = dist[j][i] + dist[i][x];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][x] + dist[x][j])
                    dist[i][j] = dist[i][x] + dist[x][j];


        int y = 0;
        for (auto& a : dist)
            for (auto& b : a)
                y += (b >= 1e10 ? 0 : b);
        ans.push_back(y);
    }

    reverse(ans.begin(), ans.end());
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
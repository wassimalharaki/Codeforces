#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 5001;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<array<int, 3>> a(n);
    for (auto& [x, y, z] : a)
        cin >> x >> y >> z;
    
    v<int> in(n);
    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        in[y - 1]++;
    }

    for (int i = 0; i < n; i++) {
        adj[i].push_back(i);
        in[i]++;
    }

    v<int> dp(N, INT_MIN), ndp(N);
    dp[k] = 0;
    for (int i = 0; i < n; i++) {
        fill(ndp.begin(), ndp.end(), INT_MIN);
        v<int> b;
        for (int& j : adj[i])
            if (--in[j] == 0)
                b.push_back(a[j][2]);
        sort(b.rbegin(), b.rend());
        m = b.size();

        for (int j = a[i][0]; j + a[i][1] < N; j++) {
            ndp[j + a[i][1]] = max(ndp[j + a[i][1]], dp[j]);

            int x = 0;
            for (k = 0; k < m; k++) {
                x += b[k];
                int l = j + a[i][1] - k - 1;
                if (l >= 0)
                    ndp[l] = max(ndp[l], x + dp[j]);
            }
        }
        swap(dp, ndp);
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << (ans >= 0 ? ans : -1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
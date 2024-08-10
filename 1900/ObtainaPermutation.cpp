#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v a(n, v<int>(m));
    for (auto& x : a)
        for (auto& y : x)
            cin >> y;
    
    int ans = 0;
    for (int j = 0; j < m; j++) {
        v<int> need(n);
        for (int i = 0; i < n; i++) {
            if (a[i][j] < j + 1) continue;
            if ((a[i][j] - (j + 1)) % m) continue;
            int k = (a[i][j] - (j + 1)) / m;
            if (k >= n) continue;
            if (i >= k) need[i - k]++;
            else need[i + n - k]++;
        }
        int curr = n;
        for (int i = 0; i < n; i++)
            curr = min(curr, i + n - need[i]);
        ans += curr;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
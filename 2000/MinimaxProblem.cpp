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
    
    array<int, 2> ans;
    auto check = [&](int k) -> bool {
        v<int> have(1 << m, -1);
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = 0; j < m; j++)
                if (a[i][j] >= k)
                    x += 1 << j;
            if (x == (1 << m) - 1) {
                ans = {i, i};
                return 1;
            }
            if (have[((1 << m) - 1) ^ x] != -1) {
                ans = {i, have[((1 << m) - 1) ^ x]};
                return 1;
            }
            for (int y = x; y and have[y] == -1; y = x & (y - 1))
                have[y] = i;
        }
        return 0;
    };

    int lo = 0, hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << ans[0] + 1 << " " << ans[1] + 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
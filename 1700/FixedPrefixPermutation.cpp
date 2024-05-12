#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> a(n, v<int>(m));
    set<v<int>> ok;
    for (auto& x : a) {
        for (int& y : x)
            cin >> y, y--;
        v<int> curr(m, -1);
        int look = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                if (x[j] == look) {
                    curr[j] = look++;
                    break;
                }
            ok.insert(curr);
        }
    }

    for (int i = 0; i < n; i++) {
        v<int> curr(m, -1);
        int ans = 0;
        for (int j = 0; j < m; j++) {
            curr[a[i][j]] = ans;
            if (ok.count(curr))
                ans++;
            else
                break;
        }
        cout << ans << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
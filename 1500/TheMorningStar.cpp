#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<map<int, int>> lines(4);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        lines[0][x]++;
        lines[1][y]++;
        lines[2][x - y]++;
        lines[3][y + x]++;
    }

    int ans = 0;
    for (auto& m : lines)
        for (auto& [key, val] : m)
            ans += val * (val - 1);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
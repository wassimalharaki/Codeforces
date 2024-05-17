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

const int N = 200;

void solve() {
    int n; cin >> n;

    array<v<int>, N> ind;
    v<array<int, N>> pref(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        ind[x].push_back(i);
        pref[i + 1] = pref[i];
        pref[i + 1][x]++;
    }

    auto get = [&](int l, int r) -> int {
        int x = 0;
        for (int i = 0; i < N; i++)
            x = max(x, pref[r + 1][i] - pref[l][i]);
        return x;
    };

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int m = ind[i].size();
        ans = max(ans, m);
        for (int j = 1; 2 * j <= m; j++) {
            int l = ind[i][j - 1], r = ind[i][m - j];
            ans = max(ans, 2 * j + get(l + 1, r - 1));
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
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

const int mod = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;

    v<v<int>> cnt(k + 1, v<int>(n + 1));
    cnt[k][0] = 1;
    bool alt = 1;
    for (int i = k - 1; i > 0; i--) {
        if (alt) {
            cnt[i][0] = cnt[i + 1][0];
            for (int j = 1; j < n; j++)
                cnt[i][j] = (cnt[i][j - 1] + cnt[i + 1][j]) % mod;
        }
        else
            for (int j = n - 1; j > 0; j--)
                cnt[i][j] = (cnt[i][j + 1] + cnt[i + 1][j]) % mod;
        alt = !alt;
    }

    int ans = 0;
    for (auto& a : cnt)
        for (auto& b : a)
            ans = (ans + b) % mod;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
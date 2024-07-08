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

int dp[20][4][2][2];
int go(string& s, int n, int x = 3, bool lz = 1, bool t = 1) {
    if (dp[n][x][lz][t] != -1)
        return dp[n][x][lz][t];
    if (!n or !x) return dp[n][x][lz][t] = 1;

    int r = (t ? s[s.size() - n] - '0' : 9);

    int ans = 0;
    for (int i = 0; i < r; i++)
        if (i == 0)
            ans += go(s, n - 1, x, lz, 0);
        else
            ans += go(s, n - 1, x - 1, 0, 0);
    ans += go(s, n - 1, x - (r != 0), 0, t);
    return dp[n][x][lz][t] = ans;
}

void solve() {
    int l, r; cin >> l >> r;
    string s = to_string(l - 1), t = to_string(r);

    memset(dp, -1, sizeof(dp));
    int x = go(t, t.size());
    memset(dp, -1, sizeof(dp));
    int y = go(s, s.size());

    cout << x - y << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
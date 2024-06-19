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
    string s; cin >> s;
    int n = s.size();
    
    v dp(n, v<int>(n, -1));
    auto go = [&](int l, int r, auto&& go) -> int {
        if (dp[l][r] != -1) return dp[l][r];
        if (l + 1 == r)
            return dp[l][r] = s[l] != s[r];

        go(l + 2, r, go);
        go(l + 1, r - 1, go);
        go(l, r - 2, go);

        if ((dp[l + 2][r] == 1 or dp[l][r - 2] == 1)
                and dp[l + 1][r - 1] == 1)
            return dp[l][r] = 1;

        if (dp[l + 2][r] == 1 and dp[l + 1][r - 1] == 0 and s[l] < s[r])
            return dp[l][r] = 1;

        if (dp[l][r - 2] == 1 and dp[l + 1][r - 1] == 0 and s[r] < s[l])
            return dp[l][r] = 1;

        if (dp[l + 1][r - 1] == 1 and dp[l + 2][r] == 0 and s[l] < s[l + 1])
            return dp[l][r] = 1;
        
        if (dp[l + 1][r - 1] == 1 and dp[l][r - 2] == 0 and s[r] < s[r - 1])
            return dp[l][r] = 1;
        
        if (s[l] < s[l + 1] and s[l] < s[r])
            return dp[l][r] = 1;

        if (s[r] < s[r - 1] and s[r] < s[l])
            return dp[l][r] = 1;
        
        return dp[l][r] = 0;
    };
    go(0, --n, go);

    cout << (dp[0][n] == 1 ? "Alice" : "Draw") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
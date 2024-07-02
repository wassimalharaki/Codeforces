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
    int n, m; cin >> n >> m;

    v<v<int>> end(n + 1);
    v<int> start(n + 1), dp(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        start[l]++; end[r].push_back(l);
    }

    multiset<int> lefts;
    for (int i = 1; i <= n; i++) {
        while (start[i]--)
            lefts.insert(i);
        for (int& a : end[i - 1])
            lefts.erase(lefts.find(a));
        if (not lefts.empty())
            dp[i] = lefts.size() + dp[*lefts.begin() - 1];
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
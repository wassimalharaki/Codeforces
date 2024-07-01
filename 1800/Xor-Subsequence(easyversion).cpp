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
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> dp(n, 1);
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n and (i ^ j) <= 400; j++)
            if ((a[i] ^ j) < (a[j] ^ i))
                dp[i] = max(dp[i], 1 + dp[j]);
    cout << *max_element(dp.begin(), dp.end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
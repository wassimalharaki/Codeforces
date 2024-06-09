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
    int n; cin >> n;

    v<int> a(n << 1);
    for (int& x : a) cin >> x;

    v<int> b{1};
    int prev = a[0];
    for (int i = 1; i < n << 1; i++)
        if (a[i] < prev)
            b.back()++;
        else
            b.push_back(1), prev = a[i];
    
    v<int> dp((n << 1) + 1);
    dp[0] = 1;
    for (int& x : b)
        for (int i = n << 1; i >= 0; i--)
            if (dp[i] and x + i <= n << 1)
                dp[x + i] = dp[i];
    cout << (dp[n] ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
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

array<int, 2> bruteforce(v<int>& a) {
    int n = a.size();
    array<int, 2> ans{(int) 1e9, (int) 1e9};

    for (int mask = 0; mask < (1 << n); mask++) {
        v<int> b{1};
        for (int i = 1; i < n; i++) {
            int prev = (1 << (i - 1)) & mask ? !a[i - 1] : a[i - 1];
            int curr = (1 << i) & mask ? !a[i] : a[i];
            if (curr == prev)
                b.back()++;
            else
                b.push_back(1);
        }

        bool ok = 1;
        for (int& x : b)
            ok &= x & 1 ^ 1;
        if (not ok) continue;

        int cnt = __builtin_popcount(mask);
        if (cnt < ans[0])
            ans[0] = cnt, ans[1] = b.size();
        else if (cnt == ans[0])
            ans[1] = min(ans[1], (int) b.size());
    }
    return ans;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) {
        char c; cin >> c;
        x = c - '0';
    }

    v<int> b{1};
    for (int i = 1; i < n; i++)
        if (a[i] == a[i - 1])
            b.back()++;
        else
            b.push_back(1);
    int m = b.size();

    bool ok = 0;
    int cnt = 0, ans = 0;
    v<array<int, 2>> dp(m + 1);
    dp[0] = {1, 1};
    for (int i = 0; i < m; i++) {
        auto& x = b[i];
        if (x & 1) {
            if (ok)
                ans += cnt + 1;
            else
                cnt = 0;
            ok = !ok;
        }
        else if (ok)
            cnt++;

        if (x > 2 or (x == 2 and not ok))
            dp[i + 1] = {(int) 1e9, min(dp[i][0], 1 + dp[i][1])};
        else
            dp[i + 1] = {dp[i][1], min(dp[i][0], 1 + dp[i][1])};
    }
    cout << ans << " " << min(dp[m][1], dp[m][0]) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
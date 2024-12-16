#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    for (int i = 0; i < n; i++)
        a.push_back(a[i]);
    
    map<int, int> dp;
    int curr = 0, ans = n;
    v<int> pref(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        curr += a[i];
        pref[i] = curr;
        dp[curr]++;
        if (i - n >= 0)
            dp[pref[i - n]]--;
        if (i + 1 >= n)
            ans = min(ans, n - dp[curr]);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
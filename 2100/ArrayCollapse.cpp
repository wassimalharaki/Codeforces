#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;

void add(int& a, int b) { a = (a + b % mod + mod) % mod; }

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> l(n);
    stack<int> mono;
    for (int i = 0; i < n; i++) {
        while (mono.size() and a[mono.top()] > a[i])
            mono.pop();
        l[i] = (mono.size() ? mono.top() : -1) + 1;
        mono.push(i);
    }

    v<int> dp(n + 1), dp2(n + 1), pref(n + 2);
    dp[0] = dp2[0] = pref[1] = 1;
    for (int i = 1; i <= n; i++) {
        add(dp[i], pref[i] - pref[l[i - 1]]);
        add(dp[i], dp2[l[i - 1]] - dp[l[i - 1]]);
        add(dp2[i], dp[i] + dp2[l[i - 1]] - (l[i - 1] == 0));
        add(pref[i + 1], pref[i] + dp[i]);
    }
    add(dp[n], dp2[l[n - 1]] - (l[n - 1] == 0));
    cout << dp.back() << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
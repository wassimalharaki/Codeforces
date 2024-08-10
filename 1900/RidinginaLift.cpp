#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n, a, b, k; 
    cin >> n >> a >> b >> k;
    --a, --b;

    v<int> dp(n), ndp(n), diff(n + 1);
    dp[a] = 1;
    while (k--) {
        fill(ndp.begin(), ndp.end(), 0ll);
        fill(diff.begin(), diff.end(), 0ll);
        for (int i = 0; i < n; i++) {
            if (i == b) continue;
            int d = abs(i - b) - 1;
            int l = max(0ll, i - d);
            int r = min(n - 1, i + d);
            add(diff[l], dp[i]);
            add(diff[r + 1], - dp[i]);
            add(ndp[i], - dp[i]);
        }

        int curr = 0;
        for (int i = 0; i < n; i++) {
            add(curr, diff[i]);
            add(ndp[i], curr);
        }
        swap(ndp, dp);
    }
    int ans = 0;
    for (int& x : dp)
        add(ans, x);
    cout << (ans + mod) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
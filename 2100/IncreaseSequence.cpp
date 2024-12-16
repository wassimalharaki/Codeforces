#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 1e9 + 7;

void add(int& a, int b) { a = (a + b % mod + mod) % mod; }

int f(v<int>& a, int k) {
    if (a.empty()) return 1;
    if (k - a[0] > 1 or k - a.back() > 1)
        return 0;
    
    int n = a.size();
    v<v<int>> dp(n + 1, v<int>(n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        int x = k - a[i - 1];
        add(dp[i][x], dp[i - 1][x]);
        add(dp[i][x - 1], x * dp[i - 1][x]);

        x--;
        add(dp[i][x], (x + 1) * dp[i - 1][x]);
        add(dp[i][x + 1], dp[i - 1][x]);
    }
    return dp[n][0];
}

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;
    if (*max_element(a.begin(), a.end()) > k)
        return void(cout << 0 << nl);
    for (int i = 0; i < n - 1; i++)
        if (abs(a[i] - a[i + 1]) > 1)
            return void(cout << 0 << nl);
    
    v<int> b;
    int ans = 1;
    for (int& x : a)
        if (x == k) {
            ans = ans * f(b, k) % mod;
            b.clear();
        }
        else
            b.push_back(x);
    cout << ans * f(b, k) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
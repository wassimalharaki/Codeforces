#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 700;

bool bruteforce(v<int>& a) {
    int n = a.size();
    v adj(n, bitset<N>());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                adj[i][j] = gcd(a[i], a[j]) > 1;

    v dp(n, v(n, bitset<N>()));
    for (int i = 0; i < n; i++)
        for (int j = 0; j + i < n; j++) {
            int cnt = 0;
            for (int k = j; k <= j + i and cnt < 10; k++)
                if ((k == j or dp[j][k - 1][k]) and (k == j + i or dp[k + 1][j + i][k]))
                    dp[j][i + j] |= adj[k], cnt++;
            cnt = 0;
            for (int k = j + i; k >= j and cnt < 10; k--)
                if ((k == j or dp[j][k - 1][k]) and (k == j + i or dp[k + 1][j + i][k]))
                    dp[j][i + j] |= adj[k], cnt++;
        }
    return dp[0][n - 1].any();
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    bool bf = bruteforce(a);
    cout << (bf ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
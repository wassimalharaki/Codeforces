#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int inf = 1e18;

void solve() {
    int n, m, x; cin >> n >> m >> x;

    v<int> a(n);
    for (int& x : a) cin >> x;

    if (m == 1) {
        int ans = accumulate(a.begin(), a.end(), 0ll);
        return void(cout << (x == n ? ans : -1) << nl);
    }

    v dp(x + 1, v<array<int, 2>>(n + 1, {-inf, -inf}));
    dp[0][0] = {0, 0};

    deque<int> prev, curr;
    for (int i = 1; i <= x; i++) {
        prev.push_back(0);
        curr.push_back(0);
        for (int j = 1; j <= n; j++) {
            while (curr.back() <= j - m)
                curr.pop_back();
            dp[i][j][0] = dp[i][curr.back()][1];

            while (prev.back() < j - m)
                prev.pop_back();
            dp[i][j][1] = a[j - 1] + dp[i - 1][prev.back()][1];

            while (curr.size() and dp[i][curr.front()][1] <= dp[i][j][1])
                curr.pop_front();
            curr.push_front(j);
            while (prev.size() and dp[i - 1][prev.front()][1] <= dp[i - 1][j][1])
                prev.pop_front();
            prev.push_front(j);
        }
        prev.clear();
        curr.clear();
    }

    int ans = max(dp[x][n][0], dp[x][n][1]);  
    cout << (ans < 0 ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
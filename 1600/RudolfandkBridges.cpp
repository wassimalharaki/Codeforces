#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    v<v<int>> nums(n, v<int>(m));
    for (v<int>& a : nums) for (int& b : a)
        cin >> b, b++;

    v<int> each_row(n);
    auto calc = [&](int i) -> void {
        if (d == m) {
            each_row[i] = 2;
            return;
        }

        v<int> dp(m);
        dp[0] = 1;
        multiset<int> use{1};
        for (int j = 1; j < d; j++) {
            dp[j] = nums[i][j] + 1;
            use.insert(dp[j]);
        }

        for (int j = d; j < m; j++) {
            dp[j] = nums[i][j] + *use.begin();
            use.insert(dp[j]);
            if (j - d - 1 >= 0)
                use.erase(use.find(dp[j - d - 1]));
        }
        each_row[i] = dp[m - 1];
    };
    for (int i = 0; i < n; i++)
        calc(i);
    
    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += each_row[i];

    int curr = ans;
    for (int i = k; i < n; i++) {
        curr -= each_row[i - k];
        curr += each_row[i];
        ans = min(ans, curr);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
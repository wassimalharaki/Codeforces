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
    int n; cin >> n;

    v<int> nums(n), cnt(n + 1), prefix(n + 1);
    for (int& a : nums) cin >> a, cnt[a]++;
    partial_sum(all(nums), prefix.begin() + 1);
    v<bool> exists(n + 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) {
            int sum = prefix[i + 1] - prefix[j];
            if (sum <= n)
                exists[sum] = 1;
        }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (exists[i])
            ans += cnt[i];
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
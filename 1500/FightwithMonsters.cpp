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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int c = a + b;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<int> skips(n);
    for (int i = 0; i < n; i++)
        skips[i] = (nums[i] - (nums[i] + c - 1) / c * c + c - 1) / a;
    sort(all(skips));

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (k - skips[i] >= 0)
            k -= skips[i], ans++;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
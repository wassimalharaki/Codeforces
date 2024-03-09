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

const int mod = 1e9 + 7;

int choose(int n, int r) {
    if (r > n) return 0;
    if (r == 0) return 1;
    if (r == 1) return n;
    if (r == 2) return n * (n - 1) / 2;
    if (r == 3) return n * (n - 1) * (n - 2) / 6;
}

void solve() {
    int n, m, k; cin >> n;
    m = 3, k = 2;

    v<int> nums(n + 1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums[a]++;
    }

    int curr = 0;
    for (int i = 1; i <= k + 1 and i <= n; i++)
        curr += nums[i];
    
    int ans = choose(curr, m);
    for (int i = k + 2; i <= n; i++) {
        curr -= nums[i - k - 1];
        for (int j = 1; j <= min(nums[i], m); j++)
            ans += choose(nums[i], j) * choose(curr, m - j);
        curr += nums[i];
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
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
    int n, m; cin >> n >> m;
 
    v<int> nums(n);
    map<int, int> have;
    for (int& a : nums) {
        cin >> a;
        if (++have[a % m] > 1) {
            cout << 0;
            return;
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = ans * abs(nums[j] - nums[i]) % m;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;
 
    v<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    if (n == 1) {
        cout << 0 << nl;
        return;
    }

    int ans = 0, twos = 0, first = nums[0];
    while (nums[1] * (1 << twos) < first)
        twos++;
    ans += twos; first = nums[1];

    for (int i = 2; i < n; i++) {
        if (nums[i] > first) {
            int needed = 0;
            while (first * (1 << needed) <= nums[i])
                needed++;
            twos -= needed - 1;
            twos = max(twos, 0ll);
            ans += twos;
        }
        else {
            int needed = 0;
            while (nums[i] * (1 << needed) < first)
                needed++;
            twos += needed;
            ans += twos;
        }
        first = nums[i];
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
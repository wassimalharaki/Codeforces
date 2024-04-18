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

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<bool> dp_left(n), dp_right(n);
    for (int i = 0; i < n; i++) {
        if (i - nums[i] == 0)
            dp_left[i] = 1;
        else if (i - nums[i] > 0)
            dp_left[i] = dp_left[i] | dp_left[i - nums[i] - 1];

        if ((i == 0 or dp_left[i - 1] == 1) and i + nums[i] < n)
            dp_left[i + nums[i]] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i + nums[i] == n - 1)
            dp_right[i] = 1;
        else if (i + nums[i] < n - 1)
            dp_right[i] = dp_right[i] | dp_right[i + nums[i] + 1];

        if ((i == n - 1 or dp_right[i + 1] == 1) and i - nums[i] >= 0)
            dp_right[i - nums[i]] = 1;
    }
    
    for (int i = 0; i < n; i++)
        if (dp_left[i] and (i == n - 1 or dp_right[i + 1])) {
            cout << "YES" << nl;
            return;
        }
        else if (dp_right[i] and (i == 0 or dp_left[i - 1])) {
            cout << "YES" << nl;
            return;
        }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
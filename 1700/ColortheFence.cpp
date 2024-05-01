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

    v<int> nums(10);
    for (int i = 1; i < 10; i++)
        cin >> nums[i];
    
    int imin = 1;
    for (int i = 2; i < 10; i++)
        if (nums[i] <= nums[imin])
            imin = i;
    int m = nums[imin];

    if (m > n) {
        cout << -1 << nl;
        return;
    }

    v<int> ans;
    while (n - m >= 0) {
        ans.push_back(imin);
        n -= m;
    }

    for (int& a : ans) {
        for (int i = 9; i > a; i--) {
            if (n + m - nums[i] >= 0) {
                a = i;
                n += m - nums[i];
                break;
            }
        }
    }

    for (int& a : ans)
        cout << a;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
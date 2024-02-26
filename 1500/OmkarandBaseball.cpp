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

    int l = 0, r = n - 1;
    while (l < n) {
        if (nums[l] != l + 1)
            break;
        l++;
    }
    
    while (r >= 0) {
        if (nums[r] != r + 1)
            break;
        r--;
    }
    
    if (l > r) {
        cout << 0 << nl;
        return;
    }

    bool ok = 0;
    for (int i = l; i <= r; i++)
        if (nums[i] == i + 1)
            ok = 1;
    cout << 1 + ok << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
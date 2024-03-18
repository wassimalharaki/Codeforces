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

    v<int> nums(n - 1);
    for (int& a : nums) cin >> a;

    int max = 0, md = 0, delta = 0;
    for (int i = 0; i < nums.size(); i++) {
        delta += nums[i];
        if (delta > md) {
            md = delta;
            max = i + 1;
        }
    }

    v<int> ans(n);
    ans[max] = n;
    for (int i = max + 1; i < n; i++)
        ans[i] = ans[i - 1] + nums[i - 1];
    for (int i = max; i > 0; i--)
        ans[i - 1] = ans[i] - nums[i - 1];

    v<int> check(ans);
    sort(all(check));
    for (int i = 0; i < n; i++)
        if (check[i] != i + 1) {
            cout << -1 << nl;
            return;
        }
    
    for (int& a : ans) cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
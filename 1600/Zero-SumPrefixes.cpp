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
    nums.push_back(0);

    bool have_zero = 0;
    map<int, int> cnt;
    int imax = 0, ans = 0, curr = 0;
    for (int i = 0; i <= n; i++)
        if (nums[i] == 0) {
            if (not have_zero) {
                have_zero = 1;
                ans += cnt[0];
                cnt.clear();
                ++cnt[curr];
                imax = curr;
            }
            else {
                ans += cnt[imax];
                cnt.clear();
                ++cnt[curr];
                imax = curr;
            }
        }
        else {
            curr += nums[i];
            if (++cnt[curr] > cnt[imax])
                imax = curr;
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
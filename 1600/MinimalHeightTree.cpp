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

    v<int> blocks{0};
    for (int i = 1; i < n; i++)
        if (nums[i] > nums[i - 1])
            blocks.back()++;
        else
            blocks.push_back(1);

    int ans = 0, children = 1, next = 0;
    for (int i = 0; i < blocks.size(); i++) {
        if (next == 0) ans++;
        next += blocks[i];
        if (--children == 0) {
            children = next;
            next = 0;
        }
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
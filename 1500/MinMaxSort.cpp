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

    v<int> nums(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        pos[nums[i]] = i;
    }

    int l = n / 2, r = (n + 1) / 2 + 1;
    int prev_l = 1e6, prev_r = -1;
    if (n & 1) prev_l = prev_r = pos[n / 2 + 1];
    while (l >= 1 and r <= n)
        if (pos[l] < pos[r] and pos[l] < prev_l and pos[r] > prev_r) {
            prev_l = pos[l];
            prev_r = pos[r];
            l--, r++;
        }
        else
            break;
    cout << max(l, n - r + 1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
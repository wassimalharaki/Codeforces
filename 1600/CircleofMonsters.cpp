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

/*
question to be answered:
who to kill first?
options:
lowest hp (no)
greatest b[i] - a[i] (no)
the monster that DOES NOT die if the one before him did (no)

observation 1:
if i start with a monster, i have to kill i + 1, i + 2, i + 3 ...
*/

int safe_mod(int i, int n) {
    return (i % n + n) % n;
}

void solve() {
    int n; cin >> n;
    v<array<int, 2>> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1];

    int curr = nums[0][0];
    for (int i = 1; i < n; i++)
        curr += max(nums[i][0] - nums[i - 1][1], 0ll);

    auto get = [&](int i) {
        int j = safe_mod(i - 1, n);
        return nums[i][0] - max(nums[i][0] - nums[j][1], 0ll);
    };

    int ans = curr;
    for (int i = 1; i < n; i++) {
        curr += get(i) - get(i - 1);
        ans = min(ans, curr);
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
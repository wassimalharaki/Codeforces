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

    v<array<int, 3>> prefix(n + 1, {0, 0, 0});
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i];
        prefix[i + 1][i & 1] += nums[i];
        prefix[i + 1][2] = prefix[i + 1][1] - prefix[i + 1][0];
    }

    array<int, 2> min{0, 0};
    int max = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (!(i & 1)) sum += nums[i];
        min[i & 1] = std::min(min[i & 1], prefix[i + 1][2]);
        max = std::max(max, prefix[i + 1][2] - min[i & 1]);
    }
    cout << sum + max << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
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
    int n, q; cin >> n >> q;

    v<int> nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));

    v<int> start(n + 1), end(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        start[l]++; end[r]++;
    }

    v<int> counts;
    int curr = 0;
    for (int i = 1; i <= n; i++) {
        curr += start[i] - end[i - 1];
        if (curr)
            counts.push_back(curr);
    }
    sort(all(counts));

    int ans = 0;
    for (int i = 0; i < counts.size(); i++)
        ans += nums.end()[-(i + 1)] * counts.end()[-(i + 1)];
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
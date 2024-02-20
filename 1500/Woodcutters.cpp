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

    v<pair<int, int>> nums(n);
    for (auto& p : nums)
        cin >> p.first >> p.second;

    //in what scenario does greedy not work?
    int l = INT_MIN, ans = 1;
    for (int i = 0; i < n - 1; i++) {
        auto& p = nums[i], q = nums[i + 1];
        if (p.first - p.second > l) {
            ans++;
            l = p.first;
        }
        else if (p.first + p.second < q.first) {
            ans++;
            l = p.first + p.second;
        }
        else
            l = p.first;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
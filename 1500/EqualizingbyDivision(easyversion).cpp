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

using max_heap = priority_queue<int>;

void solve() {
    int n, k; cin >> n >> k;

    v<int> nums(n);
    for (int& a : nums) cin >> a;
    int max = *max_element(all(nums)) + 1;

    v<pair<max_heap, int>> ok(max);
    for (int& a : nums) {
        int ops = 0;
        while (1) {
            if (ok[a].first.size() < k) {
                ok[a].second += ops;
                ok[a].first.push(ops);
            }
            else if (ops < ok[a].first.top()) {
                ok[a].second -= ok[a].first.top();
                ok[a].first.pop();
                ok[a].second += ops;
                ok[a].first.push(ops);
            }
            if (a == 0) break;
            a >>= 1; ops++;
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < max; i++)
        if (ok[i].first.size() == k)
            ans = min(ans, ok[i].second);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
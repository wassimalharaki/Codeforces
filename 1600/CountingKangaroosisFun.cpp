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

    set<pair<int, int>> have;
    v<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
        have.insert(nums[i]);
    }
    sort(all(nums));

    int curr = n;
    for (int i = n / 2 - 1; i >= 0; i--) {
        auto it = have.lower_bound({2 * nums[i].first, -1});
        if (it == have.end()) continue;
        have.erase(nums[i]);
        have.erase(it);
        curr--;
    }
    cout << curr << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
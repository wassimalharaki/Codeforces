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

    deque<int> nums;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums.push_back(a);
    }

    v<pair<int, int>> ans{{-1, -1}};
    int max = *max_element(all(nums));
    while (nums.front() != max) {
        int a = nums.front();
        nums.pop_front();
        int b = nums.front();
        nums.pop_front();
        ans.push_back({a, b});
        nums.push_front(std::max(a, b));
        nums.push_back(min(a, b));
    }

    v<pair<int, int>> cycle;
    while (cycle.size() != n - 1) {
        int a = nums.front();
        nums.pop_front();
        int b = nums.front();
        nums.pop_front();
        cycle.push_back({a, b});
        nums.push_front(std::max(a, b));
        nums.push_back(min(a, b));
    }

    while (q--) {
        int x; cin >> x;
        if (x < ans.size()) {
            cout << ans[x].first << " " << ans[x].second << nl;
        }
        else {
            x -= ans.size();
            x %= n - 1;
            cout << cycle[x].first << " " << cycle[x].second << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
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

    v<v<int>> nums(n + 1);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums[a].push_back(i);
    }

    v<int> ans(n, -1);
    set<int> have;
    for (int i = 1; i <= n; i++)
        have.insert(i);

    for (int i = 1; i <= n; i++) {
        if (nums[i].size() == 0) continue;
        int prev = -1, diff = 0;
        for (int& j : nums[i]) {
            diff = max(diff, j - prev);
            prev = j;
        }
        diff = max(diff, n - prev);
        auto it = have.lower_bound(diff);
        while (it != have.end()) {
            int x = *it;
            ans[x - 1] = i;
            it++;
            have.erase(x);
        }
    }
    for (int& a : ans)
        cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
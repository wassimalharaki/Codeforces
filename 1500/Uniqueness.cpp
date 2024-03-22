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
    map<int, int> cnt;
    for (int& a : nums) {
        cin >> a;
        cnt[a]++;
    }
    map<int, int> kill;
    for (auto& [key, val] : cnt)
        if (val > 1)
            kill[key] = val - 1;

    int ans = (kill.empty() ? 0 : INT_MAX);
    for (int i = 0; i < n; i++) {
        map<int, int> me;
        int status = 0;
        for (int j = i; j < n; j++) {
            if (kill.count(nums[j])) {
                int& x = ++me[nums[j]];
                if (x == kill[nums[j]])
                    status++;
            }
            if (status == kill.size())
                ans = min(ans, j - i + 1);
        }
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
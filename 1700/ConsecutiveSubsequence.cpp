#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    map<int, int> ok;
    v<int> nums(n);
    for (int& a : nums) {
        cin >> a;
        ok[a] = max(ok[a], ok[a - 1] + 1);
    }

    int max_val = 0, max;
    for (auto& [key, val] : ok)
        if (val > max_val) {
            max_val = val;
            max = key;
        }

    v<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] == max) {
            ans.push_back(i + 1);
            max--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
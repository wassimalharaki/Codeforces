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
    int n, k; cin >> n >> k;

    v<int> nums(n);
    v<v<int>> rem(k);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        rem[nums[i] % k].push_back(i);
    }

    v<bool> dead(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dead[i]) continue;
        dead[i] = 1;
        int start = (k - nums[i] % k) % k;
        bool ok = 0;
        for (int j = start; j < k; j++) {
            while (not rem[j].empty() and dead[rem[j].back()])
                rem[j].pop_back();
            if (rem[j].empty()) continue;
            ans += (nums[i] + nums[rem[j].back()]) / k;
            dead[rem[j].back()] = 1;
            rem[j].pop_back();
            ok = 1;
            break;
        }
        if (ok) continue;

        for (int j = 0; j < start; j++) {
            while (not rem[j].empty() and dead[rem[j].back()])
                rem[j].pop_back();
            if (rem[j].empty()) continue;
            ans += (nums[i] + nums[rem[j].back()]) / k;
            dead[rem[j].back()] = 1;
            rem[j].pop_back();
            break;
        }
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
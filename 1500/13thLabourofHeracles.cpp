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
    int sum = accumulate(all(nums), 0ll);

    v<int> deg(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        deg[a]++; deg[b]++;
    }

    v<pair<int, int>> use;
    for (int i = 1; i <= n; i++) 
        if (deg[i] > 1)
            use.push_back({nums[i - 1], deg[i] - 1});
    sort(use.rbegin(), use.rend());
    
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        cout << sum << " ";
        if (j < use.size()) {
            sum += use[j].first;
            if (--use[j].second == 0)
                j++;
        }
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
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
    int n, m; cin >> n >> m;

    v<pair<v<int>, int>> nums(m);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        nums[i].first.resize(k);
        nums[i].second = i;
        for (int& b : nums[i].first)
            cin >> b;
    }
    sort(nums.begin(), nums.end(), [](auto& l, auto& r) {
        return l.first.size() < r.first.size();
    });

    v<int> cnt(n + 1), ans(m);
    for (auto& a : nums) {
        int imin = a.first[0];
        for (int& b : a.first)
            if (cnt[b] < cnt[imin])
                imin = b;
        
        if (++cnt[imin] > (m + 1) / 2) {
            cout << "NO" << nl;
            return;
        }
        ans[a.second] = imin;
    }
    
    cout << "YES" << nl;
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
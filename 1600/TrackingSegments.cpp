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
    int n, m; cin >> n >> m;

    v<array<int, 2>> nums(m);
    for (auto& a : nums)
        cin >> a[0] >> a[1];
    
    int q; cin >> q;
    v<int> change(q);
    for (int& a : change) cin >> a;

    int lo = 1, hi = q, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        v<int> mark(n);
        for (int i = 0; i < mid; i++)
            mark[change[i] - 1] = 1;
        
        v<int> prefix(n + 1);
        partial_sum(all(mark), prefix.begin() + 1);

        bool ok = 0;
        for (int i = 0; i < m; i++)
            if (prefix[nums[i][1]] - prefix[nums[i][0] - 1]
                    > (nums[i][1] - nums[i][0] + 1) / 2)
                ok = 1;

        if (ok)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
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
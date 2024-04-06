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

    v<int> nums(n);
    for (int& a: nums) cin >> a;

    v<int> good(n), bad;
    for (int i = 0; i < n; i++)
        if (nums[i] <= q)
            good[i] = 1;
        else
            bad.push_back(i);
    int m = bad.size();

    v<int> ans = good;
    int lo = 1, hi = m;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        bool ok = 1;
        int k = q;
        v<int> current = good;
        for (int i = bad[m - mid]; i < n; i++)
            if (nums[i] > k) {
                if (k <= 0)
                    ok = 0;
                k--;
                current[i] = 1;
            }
        
        if (ok)
            ans = current, lo = mid + 1;
        else
            hi = mid - 1;
    }

    for (int& a : ans)
        cout << a;
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}
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
    int n, have; cin >> n >> have;
    have *= 8;

    auto get = [&](unsigned int x) {
        return n * __lg(bit_ceil(x));
    };

    map<int, int> ok;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ok[a]++;
    }
    v<int> nums;
    for (auto& [key, val] : ok)
        nums.push_back(val);
    int m = nums.size();

    v<int> left(m + 1), right(m + 1);
    for (int i = 0; i < m; i++) {
        left[i + 1] = left[i] + nums[i];
        right[i + 1] = right[i] + nums[m - i - 1];
    }

    int lo = 0, hi = m - 1, ans = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        
        if (get(m - mid) > have)
            lo = mid + 1;
        else {
            hi = mid - 1;
            for (int i = 0; i <= mid; i++)
                ans = min(ans, left[i] + right[mid - i]);
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
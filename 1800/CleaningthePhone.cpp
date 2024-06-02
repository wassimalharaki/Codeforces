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

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> one, two;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x == 1 ? one.push_back(a[i]) : two.push_back(a[i]);
    }
    sort(one.rbegin(), one.rend());
    sort(two.rbegin(), two.rend());

    auto check = [&](int k) -> bool {
        int x = 0, i = 0, j = 0, curr = 0;

        for (; curr < k - 1 and j < two.size(); j++)
            x += two[j], curr += 2;
        j--;
        for (; curr < k and i < one.size(); i++)
            x += one[i], curr++;
        if (x >= m) return 1;

        for (; j >= 0 and i < one.size(); j--, i++) {
            x -= two[j];
            x += one[i];
            if (i + 1 < one.size()) x += one[++i];
            if (x >= m) return 1;
        }
        return 0;
    };

    int lo = 0, hi = one.size() + 2 * two.size(), ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid - 1, ans = mid;
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
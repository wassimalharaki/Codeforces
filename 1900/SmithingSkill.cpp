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

    v<array<int, 2>> a(n);
    for (auto& x : a)
        cin >> x[1];
    for (auto& x : a) {
        int y; cin >> y;
        x[0] = x[1] - y;
    }
    v<int> b(m);
    for (int& x : b) cin >> x;
    sort(a.begin(), a.end());

    v<array<int, 2>> fix{a[0]};
    for (int i = 1; i < n; i++)
        if (a[i][1] < fix.back()[1])
            fix.push_back(a[i]);
    a.swap(fix);
    n = a.size();

    int ans = 0;
    v<int> cnt(1e6);
    for (int& y : b) {
        if (y < a[0][1]) {
            cnt[y]++;
            continue;
        }
        int x = (y - a[0][1]) / a[0][0] + 1;
        y -= a[0][0] * x;
        ans += 2 * x;
        if (y >= 0) cnt[y]++;
    }

    int j = 1;
    for (int i = 1e6 - 1; i >= 0 and j < n; i--) {
        if (cnt[i] == 0) continue;
        while (j < n and a[j][1] > i)
            j++;
        if (j == n) break;
        int x = (i - a[j][1]) / a[j][0] + 1;
        int k = i - a[j][0] * x;
        ans += 2 * x * cnt[i];
        if (k >= 0)
            cnt[k] += cnt[i];
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
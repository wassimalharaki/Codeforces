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

    v<int> a(n);
    for (int& x : a) cin >> x;

    auto bad = [&](int l, int r) -> bool {
        for (int i = l; i <= r; i++)
            for (int j = i + 1; j <= r; j++)
                for (int k = j + 1; k <= r; k++)
                    if (a[i] <= a[j] and a[j] <= a[k])
                        return 1;
                    else if (a[i] >= a[j] and a[j] >= a[k])
                        return 1;
        return 0;
    };

    int l = 0, r = 0, ans = 0;
    while (r < n) {
        while (bad(l, r)) l++;
        ans += r++ - l + 1;
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